#include "parn.h"

int parn(int a){
    int original = a;
    int dig = 0;
    int rev = 0;

    while(a != 0){
        dig = a % 10;
        rev = rev * 10 + dig;
        a /= 10;
    }

    return (original == rev);
}

