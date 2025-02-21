/* AIM -> To implement Producer consumer problem using semaphores */

#include<stdio.h>

int mutex = 1; 
int empty = 3; 
int full = 0;
int x = 0;

int wait(int s) {
	return(--s);
}

int signal(int s) {
	return(++s);
}

void producer() {
	mutex = wait(mutex);
	
	empty = wait(empty);
	full = signal(full);
	printf("--- Producer produced process %d ---\n",++x);
	
	mutex = signal(mutex);
}

void consumer() {
	mutex = wait(mutex);
	
	full = wait(full);
	empty = signal(empty);
	printf("--- Consumer removed process %d---\n",x--);
	
	mutex = signal(mutex);
} 

int main() {
	int process_nbr;
	
	
	while(1) {
		printf("Enter the process number to run:\n1 -> Producer\n2 -> Consumer\n3 -> Exit\n");
		scanf("%d",&process_nbr);
	
		switch(process_nbr) {
			case 1:
				if(empty != 0 && mutex == 1) {
					producer();
				}
				else {
					printf("!!! Space is full !!!\n");
				}
				break;
				
			case 2:
				if(full != 0 && mutex == 1) {
					consumer();
				}
				else {
					printf("!!! No Process to consume !!!\n");
				}
				break;
				
			case 3:
				printf("|| Exiting Program.... ||\n");
				return 0;
				break;
			
			default:
				printf("!! Enter valid process number !!\n");
				break;
		}
	}
}
