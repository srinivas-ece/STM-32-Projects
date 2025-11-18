#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid=fork();
	if(pid==0){
		printf("Child: I will now replace myself with 'ls -l'\n");
		execl("/bin/ls","-ls","-l", NULL);
		printf("Child: exec() failed!\n");
	}
	else{
		printf("Parent: Waiting for child to finish...\n");
		wait(NULL);
		printf("Parent: Child completed.\n");
	}
	return 0;
}
