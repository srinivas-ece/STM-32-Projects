#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num;
    printf("enter a long integer: ");
    scanf("%u", &num);

    printf("The 8 nibbles are:\n");
    for (int i = 7; i >= 0; i--) {
        unsigned int nibble = (num >> (i*4)) & 0xF;  
        printf("nibble %d = %X\n", i , nibble); // print in HEX
    }

    return 0;
}
