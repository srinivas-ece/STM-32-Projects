#include<stdio.h>
int main(){
    unsigned int num;
    printf("\nenter a number: ");
    scanf("%u",&num);

    int size=0,count = num;

    while(count!=0){
        count=count/2;
        size++;
    }
    unsigned int bit;
    printf("enter bit position between lsb:1 to msb:%d: ",size);
    scanf("%u",&bit);
    
    if((num&(1<<bit))==0){
        printf("bit is 0");
    }else{
        printf("nit is 1");
    }

    //set the bit
    num=(1<<bit)|num;
    printf("\n%d",num);    
}