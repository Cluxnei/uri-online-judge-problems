#include <stdio.h>
#include <string.h>

int containsChar(char haystack[30], char needle) {
    for (int i = 0, t = strlen(haystack); i < t; i++) {
        if (needle == haystack[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while(n--) {
        char dieta[30], manha[30], almoco[30], missing[30], done[30];
        int d = 0, m = 0;
        fgets(dieta, 30, stdin);
        fgets(manha, 30, stdin);
        fgets(almoco, 30, stdin);
        dieta[strlen(dieta) - 1] = '\0';
        manha[strlen(manha) - 1] = '\0';
        almoco[strlen(almoco) - 1] = '\0';

        for (int i = 0, t = strlen(dieta); i < t; i++) {
            if (!containsChar(manha, dieta[i]) && !containsChar(almoco, dieta[i])) {
                missing[m++] = dieta[i];
            }
        }
        missing[m] = '\0';

        int cheater = 0;
        
        for (int i = 0; i < m; i++) {
            if (!containsChar(dieta, missing[i])) {
                cheater = 1;
                break;
            }
        }

        puts(cheater ? "CHEATER" : missing);
    }
    return 0;
}