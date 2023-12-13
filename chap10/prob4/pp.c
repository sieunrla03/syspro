#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data);
int pop(struct node **top);
void printStack(struct node *top);

int main() {
    struct node *top = NULL;
    char input[100];

    while (1) {
        fgets(input, sizeof(input), stdin);

        int value;
        if (sscanf(input, "%d", &value) != 1) {
            break;
        } else {
            
            push(&top, value);
        }
    }
    
    printf("Print Stack\n");
    printStack(top);

    return 0;
}

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1; 
    }

    struct node *temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);

    return poppedValue;
}

void printStack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("\n");
}

