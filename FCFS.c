#include<stdio.h>

void main() {
	int num;
	int b_time[10],wait_t[10],TAT[10];
	double avg_tat = 0;
	double avg_wt = 0;
	
	printf("Enter number of processes: ");
	scanf("%d",&num);
	
	wait_t[0] = 0;
	printf("Enter Bust times of processes: ");
	for(int i = 0; i < num; i++) {
		scanf("%d",&b_time[i]);
		
		
		if(i >= 1) {
			wait_t[i] = wait_t[i - 1] + b_time[i - 1];
		}
		
		TAT[i] = wait_t[i] + b_time[i];
		
		avg_wt += wait_t[i]; 
		avg_tat += TAT[i];
	}
	avg_tat = avg_tat/num;
	avg_wt /= num;
	
	printf("Pid  B_time  W_time    TAT\n");
	for(int i = 0; i < num; i++) {
		printf("%d\t%d\t%d\t%d\n",i+1,b_time[i],wait_t[i],TAT[i]);
	}
	
	printf("Average Turn Around time : %f\nAverage Waiting time : %f\n",avg_tat,avg_wt);
	
	printf("\n-------------- Ghant Chart -------------\n");
	
	for(int i = 0; i < num; i++) {
			
		if(i == 3) {
			printf("|   P%d   ",i);
		}
		else{
			printf("|  P%d   ",i);
		}
		if(i == num - 1) {
			printf("|");
		}
	}
	
	printf("\n");
	for(int i = 0; i < num; i++) {
			printf("%d\t",wait_t[i]);
	}
	printf(" %d\n",TAT[num-1]);
	printf("----------------------------------------\n");
}
