#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	int pipe1[2];
	int pipe2[2];
	pid_t pid=fork();
	if(pid==0){
		close(pipe1[0]);
		char buffer[120]="srinivas\n";
//		printf("enter the name for pipe 1:");
//		scanf("%s",buffer);

		write(pipe1[1],buffer,strlen(buffer));
		close(pipe1[1]);

		close(pipe2[1]);
                char buffer1[120];
                read(pipe2[0],buffer1,sizeof(buffer1));
                close(pipe2[0]);
		printf("%s",buffer1);

		return 0;
	}else{
		close(pipe1[1]);
                char buffer2[120];
                read(pipe1[0],buffer2,sizeof(buffer2));
                close(pipe1[0]);
		printf("%s",buffer2);

                close(pipe2[0]);
                char buffer3[120]="from parent\n";
                read(pipe2[1],buffer3,strlen(buffer3));
                close(pipe2[1]);
                return 0;
	}
	return 0;
}




