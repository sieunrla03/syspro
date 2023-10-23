#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        return 1;
    }

    char line[100][100];
    int count = 0;

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        strcpy(line[count], buffer);
        count++;
    }

    fclose(fp);

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", line[i]);
    }

    return 0;
}
