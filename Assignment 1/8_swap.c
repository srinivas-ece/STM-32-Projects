#include<stdio.h>
int main(){
    int a,b;
    printf("enter a number: ");
    scanf("%d",&a);
    printf("enter a number: ");
    scanf("%d",&b);
    printf("before swap\n");
    printf("A=%d",a);
    printf("b=%d",b);

    a=a^b;
    b=a^b;
    a=a^b;

    printf("\nafter swap\n");
    printf("A=%d",a);
    printf("b=%d",b);
    return 0;
}