#include <stdio.h>
#define true 1
#define false 0
#define MAX 999999

const char numbers[10] = "0123456789";

int isNumber(char c) {
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == c) {
            return true;
        }
    }
    return false;
}

int resolveExpression(const char expression[MAX]) {
    return 0;
}

int main() {
    char expression[MAX];
    while(scanf("%s", expression) != EOF) {
        printf("%d\n", resolveExpression(expression));
    }
    return 0;
}