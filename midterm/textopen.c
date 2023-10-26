#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "How to use: %s FileName\n", argv[0]);
        return 1;
    }

    char savedText[10][1000]; 
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

    int startLine = 1;
    int endLine = 2;
    int linenum;
    char input[10];

    if (startLine >= 1 && endLine >= startLine && endLine <= totalLines) {
        for (int i = startLine; i <= endLine; i++) {
            printf("%s\n", savedText[i - 1]);
        }
    } else {
        printf("error\n");
    }
	return 0;
}
