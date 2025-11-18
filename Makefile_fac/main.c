#include <stdio.h>
#include "factorial.h"

int main() {
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    printf("Factorial = %d\n", fact(a));
    return 0;
}

