#include<stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct mgs_buffer{
	long mgs_type;
	char mgs_text[100];
};

int main(){
	key_t key;
	int mgssave;

	struct mgs_buffer mes;

	key= ftok("srinivas",65);
	printf("enter message : ");
	fgets(mes.mgs_text,sizeof(mes.mgs_text),stdin);

	msgsnd(mgssave, &mes, sizeof(mes),0);
	printf("message send\n");
	return 0;
}




