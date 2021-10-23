// #include "contafreq.h"
#include <stdio.h>

int contafreq(int num, int digito) {
   if (num % 10 == num) {
       return num % 10 == digito ? 1 : 0;
   }
   if (num % 10 == digito) {
       return 1 + contafreq(num / 10, digito);
   }
   return contafreq(num / 10, digito);
}

int main() {
    printf("%d", contafreq(1010, 0));
    return 0;
}