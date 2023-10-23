#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "How to use: %s FileName\n", argv[0]);
        return 1;
    }

    char savedText[1000][1000]; 
    int totalLines = 0;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("File Open Error");
        return 1;
    }

    int count = 0;
    int row = 0;
    char buf;

    while (fread(&buf, 1, 1, file) > 0) {
        if (buf == '\n') {
            savedText[count][row] = '\0';
            row = 0;
            count++;
        } else {
            savedText[count][row] = buf;
            row++;
        }
    }

    fclose(file);

    printf("File read success\n");
    totalLines = count;

    printf("Total line: %d\n", totalLines);
    printf("You can choose 1 ~ %d Line or *\n", totalLines);
    printf("Pls 'Enter' the line to select: ");

    int startLine, endLine, linenum;
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < totalLines; i++) {
            printf("%s\n", savedText[i]);
        }
    } else if (sscanf(input, "%d-%d", &startLine, &endLine) == 2) {
        if (startLine >= 1 && endLine >= startLine && endLine <= totalLines) {
            for (int i = startLine; i <= endLine; i++) {
                printf("%s\n", savedText[i - 1]);
            }
        } else {
            printf("error\n");
        }
    } else if (sscanf(input, "%d,%d", &startLine, &endLine) == 2) {
        if (startLine >= 1 && startLine <= totalLines && endLine >= 1 && endLine <= totalLines) {
            printf("%s\n", savedText[startLine - 1]);
            printf("%s\n", savedText[endLine - 1]);
        } else {
            printf("error\n");
        }
    } else if (sscanf(input, "%d", &linenum) == 1) {
        if (linenum >= 1 && linenum <= totalLines) {
            printf("%s\n", savedText[linenum - 1]);
        } else {
            printf("error\n");
        }
    } else {
        printf("error\n");
    }

    return 0;
}

