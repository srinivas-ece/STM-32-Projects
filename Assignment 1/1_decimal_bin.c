#include<stdio.h>
int main(){
    int num;
    printf("enter a number");
    scanf("%d",&num);
    int count=num;
    int size=0;

    while(count!=0){
        count=count/2;
        size++;
    }

    printf("%d\n",size);
    int arr[size];

    for(int i =0;i<size;i++){
        int reminder=num%2;
        num=num/2;
        arr[i]=reminder;
    }

    for(int i=size-1;i>=0;i--){
        printf("%d",arr[i]);
    }


    
    return 0;
}