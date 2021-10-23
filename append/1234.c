#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[51];
    while (scanf("%[^\n]s", str) != EOF) {
        getchar();
        for (unsigned short int i = 0, t = strlen(str), upper = 1; i < t; i++) {
            if (str[i] == ' ') {
                continue;
            }
            str[i] = upper ? toupper(str[i]) : tolower(str[i]);
            upper = !upper;
        }
        puts(str);
    }
    return 0;
}