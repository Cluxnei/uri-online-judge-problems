#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

int numberOfDigits(const char * line);

int main() {

    char line[MAX];

    scanf("%[^\n]s", line);
    getchar();
    puts(line);
    printf("%d\n", numberOfDigits(line));
    return 0;
}

int numberOfDigits(const char * line) {
    const int length = strlen(line);
    int digits = 0;
    for (int i = 0; i < length; i++) {
        if (i % 3 == 0) {
            digits++;
        }
    }
    return digits;
}