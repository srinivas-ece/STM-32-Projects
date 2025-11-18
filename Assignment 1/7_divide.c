#include<stdio.h>
int main(){
    int num;
    printf("enter a number: ");
    scanf("%d",&num);

    num=num>>1;
    printf("%d",num);
    return 0;
}   