#include <stdio.h>
#include "parn.h"

int main(){
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(parn(num)){
        printf("Given num is palindrome: %d\n", num);
    }
    else{
        printf("Given num is NOT palindrome: %d\n", num);
    }

    return 0;
}

