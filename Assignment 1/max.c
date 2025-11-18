#include<stdio.h>
int main(){
    int num1,num2;
    printf("enter a number");
    scanf("%d",&num1);
    printf("enter a number");
    scanf("%d",&num2);

    int c=num1-num2;

    if((c>>15)==0){
        printf("A is max");
    }else{
        printf("B is max");
    }
    return 0;
}