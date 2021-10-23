#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 900000

typedef unsigned short int usi;

int mininumStepsToChangeAtoB(const char* a, const char* b);
int indexOfChar(const char* haystack, const char needle);

int main() {
    usi cases;
    scanf("%hu", &cases);
    char a[MAX], b[MAX];
    while (cases--) {
        scanf("%s %s", a, b);
        printf("%d\n", mininumStepsToChangeAtoB(a, b));
    }
    return 0;
}


int indexOfChar(const char* haystack, const char needle) {
    const int length = strlen(haystack);
    for (int i = 0; i < length; i++) {
        if (haystack[i] == needle) {
            return i;
        }
    }
    return -1;
}

int stepsToChangaAIntoB(const char a, const char b) {
    if (a == b) {
        return 0;
    } else if (a == 'z' && b == 'a') {
        return 1;
    }
    const char alphabet[28] = "abcdefghijklmnopqrstuvwxyz";
    const int indexOfA = indexOfChar(alphabet, a);
    const int indexOfB = indexOfChar(alphabet, b);
    return (indexOfB < indexOfA) ? (26 - indexOfA + indexOfB) : (indexOfB - indexOfA);
}

int mininumStepsToChangeAtoB(const char* a, const char* b) {
    const int length = strlen(a);
    int steps = 0;
    for (int i = 0; i < length; i++) {
        steps += stepsToChangaAIntoB(a[i], b[i]);
        //printf("%c -> %c = %d\n", a[i], b[i], steps);
    }
    return steps;
}