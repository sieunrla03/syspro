#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int Line = 0;
    int Index = 1;

    if (argc > 2 && strcmp(argv[1], "-n") == 0) {
        Line = 1;
        Index = 2;
    }

    for (int i = Index; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            continue;
        }

        int c;
        int linenum = 1;
        int empty = 1;

        while ((c = getc(fp)) != EOF) {
            if (empty && Line) {
                printf("%d: ", linenum);
                empty = 0;
            }
            putc(c, stdout);
            if (c == '\n') {
                linenum++;
                empty = 1;
            }
        }
		if(fp != stdin){
        	fclose(fp);
		}
    }

    return 0;
}
