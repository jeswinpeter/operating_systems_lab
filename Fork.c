#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>



int main() {
	pid_t childpid = fork();
	pid_t parent;
	pid_t child;
	
	if(childpid > 0) {
		parent = getpid();
		printf("Current running process -> Parent\n");
		printf("Parent pid -> %d\nChild pid ->%d\n\n",parent,childpid);
		wait(NULL);
	}
	
	if(childpid == 0) {
		child = getpid();
		
		parent = getppid();
		printf("Current running process -> Child\n");
		printf("Parent pid -> %d\nChild pid -> %d\n",parent, child);
	}
	
	if(childpid < 0) {
		printf("Fork function failed\n");
	}
	
	return 0;
}
