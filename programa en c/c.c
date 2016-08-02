#include <stdio.h>

int main() {
    printf("Factorial hecho en C\n");
    int x;
    double fact=1;
    printf("Escriba el numero: ");
    scanf("%i",&x);

    while(x>1)
        fact*=x--;

    printf("Factorial =%lf",fact);
}
