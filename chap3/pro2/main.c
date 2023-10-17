#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINE 100

int main() {
    char line[5][MAXLINE]; 
    int cnt = 0;
    int len;
    char temp[MAXLINE]; 

    while (cnt < 5) {
        printf("Enter >> ");
        fgets(line[cnt], MAXLINE, stdin);
        line[cnt][strcspn(line[cnt], "\n")] = '\0';
        cnt++;
    }

    for (cnt = 0; cnt < 5; cnt++) {
        for (int j = 0; j < 5; j++) {
            if (strlen(line[cnt]) < strlen(line[j])) {
                strcpy(temp, line[cnt]);
                strcpy(line[cnt], line[j]);
                strcpy(line[j], temp);
            }
        }
    }

    printf("-----------------------\n");
    for (cnt = 0; cnt < 5; cnt++) {
        printf("%s\n", line[cnt]);
    }

    return 0;
}

