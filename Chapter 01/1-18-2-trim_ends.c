#include <stdio.h>

#define MAXSIZE 1000
#define IN 1
#define OUT 0
#define NOTSTARTED -1

int getLine(char line[], int limit);
int trimEnds(char line[]);

int main()
{
    char line[MAXSIZE];
    while (getLine(line, MAXSIZE) > 0) {
        int size = trimEnds(line);
        if (size != 0){
            printf("%s", line);
        }
    }

    return 0;
}

int getLine(char line[], int limit) 
{
    int c, i = 0;
    while (i < limit && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    
    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
}

int trimEnds(char line[])
{
    int start = NOTSTARTED, end = 0;
    int state = OUT;
    for (int i = 0; line[i] != '\n'; i++) {
        int isWhitespace = line[i] == ' ' || line[i] == '\t';
        if (state == IN && isWhitespace) {
            state = OUT;
        }
        else if (state == OUT && !isWhitespace) {
            state = IN;
            if (start == NOTSTARTED) {
                start = i;
            }
        }
        else if (state == IN && !isWhitespace) {
            end = i;
        }
    }
    if (start == NOTSTARTED) {
        return 0;
    }

    int i;
    for (i = 0; i < (end - start + 1); i++) {
        line[i] = line[i + start];
    }
    line[i] = '\0';

    return i;
}

