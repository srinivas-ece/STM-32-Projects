#include<stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct mgs_buffer{
	long mgs_type;
	char msg_text[100];
};

int main(){
	key_t key;
	int mgssave;
	struct mgs_buffer mes;

	key=ftok("srinivas",65);
	mgssave=msgget(key,0666 | IPC_CREAT);

	msgrcv(mgssave,&mes,sizeof(mes),1,0);
	printf("receive : %s\n",mes.msg_text);

	msgctl(mgssave,IPC_RMID,NULL);
	return 0;
}

