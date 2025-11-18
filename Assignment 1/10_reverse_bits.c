#include <stdio.h>

int main() {
    int binInput;
    printf("enter a binary number: ");
    scanf("%d", &binInput);

    int rev = 0;
    int temp = binInput;

    while (temp > 0) {
        rev = (rev << 1) | (temp & 1); 
        temp =temp >> 1;                  
    }

    printf("reversed binary: %d\n", rev);

    return 0;
}
