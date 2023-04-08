#include <stdio.h>

#define MAXSIZE 1000
#define NOTENDED -1

int getLine(char line[], int limit);
int trimEnds(char line[]);

int main()
{
    char line[MAXSIZE];
    while (getLine(line, MAXSIZE) > 0) {
        int end = trimEnds(line);
        if (end != NOTENDED){
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
    int end = NOTENDED;
    int i;
    for (i = 0; line[i] != '\n'; i++) {
        if (line[i] != ' ' && line[i] != '\t') {
            end = i;
        }
    }
    line[++end] = '\n';
    line[++end] = '\0';

    return end;
}

