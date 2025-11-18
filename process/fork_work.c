#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pid=fork();
	if(pid==0){
		for(char c='a';c<'e';c++){
			printf("child work: %c\n",c);
			sleep(1);
		}
	}
	else{
		for(int i=0;i<4;i++){
			printf("parent work: %d\n",i);
			sleep(1);
		}
	}
	return 0;
}


