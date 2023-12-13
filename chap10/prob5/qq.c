#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data);
int delete(struct node **head, struct node **tail);
void printQueue(struct node *head);

int main() {
    struct node *head = NULL; 
    struct node *tail = NULL; 
    char input[100];

    while (1) {
        fgets(input, sizeof(input), stdin);
        int value;
        if (sscanf(input, "%d", &value) != 1) {
            break;
        }
        addq(&head, &tail, value);
    }

    printf("Print Queue\n");
    printQueue(head);

    return 0;
}

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1; 
    }

    struct node *temp = *head;
    int deletedValue = temp->data;

    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *head = temp->next;
    }

    free(temp);
    return deletedValue;
}

void printQueue(struct node *head) {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

