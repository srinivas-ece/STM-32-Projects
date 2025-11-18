#include<stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	int fd[2];
	pipe(fd);
	pid_t pid = fork();

	if(pid == 0){
		char buffer[120]="srinivas";
		close(fd[0]);// close the read
		write(fd[1],buffer,strlen(buffer));
		close(fd[1]);// close write
	}else{
		close(fd[1]);//close write 
		char text[122];
		read(fd[0],text,sizeof(text));
		close(fd[0]);//close read
		printf("%s",text);
	}
	return 0;
}
