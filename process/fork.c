#include<stdio.h>
#include <unistd.h>
       

int main(){
	printf("hii i am start in parent \n ");
	pid_t pid = fork();
	printf("I am child, PpID = %d\n", getppid());

	if(pid>0){
		printf("I am parent, my child PID = %d\n", pid);

	}else if(pid==0){
		printf("I am child, PID = %d\n", getpid());
		printf("I am child, PpID = %d\n", getppid());

	}
	else{
		printf("fork failed");
	}
	return 0;
}
