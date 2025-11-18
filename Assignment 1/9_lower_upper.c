#include<stdio.h>
int main(){
    char str;
    printf("enter a lower case letter:");
    scanf("%c",&str);
    char c=str&(~32);
    printf("%c",c);
    return 0;
}