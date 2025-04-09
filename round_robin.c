#include<stdio.h>

void main() {
	int n_proce;
	int quant;
	int avg_tat = 0;
	int avg_wt = 0;

	printf("Enter no. of Processes: ");
	scanf("%d",&n_proce);
	printf("Enter Time Quantum: ");
	scanf("%d",&quant);
	// printf("Enter ");

	int b_time[n_proce];
	int Remain_time[n_proce];
	int wait_t[n_proce];
	int TAT[n_proce];
	int gantt[100];
	int gant_time[100];
	int done = 0;
	int time = 0;
	int index = 0;

	printf("Enter Burst times of process: ");
	for(int i = 0; i < n_proce; i++) {
		scanf("%d",&b_time[i]);
		Remain_time[i] = b_time[i];
		wait_t[i] = 0;
	}

	while(!done) {
		done = 1;
		
		for(int i = 0; i < n_proce; i++) {
			if(Remain_time[i] > 0) {
				done = 0;
				gantt[index] = i;
				gant_time[index++] = time;
				if(Remain_time[i] > quant) {
					time += quant;
					Remain_time[i] -= quant;
				}
				else{
					time += Remain_time[i];
					Remain_time[i] = 0;
					wait_t[i] = time - b_time[i];
				}
				
			}
		}
	}

	gant_time[index] = time;

	for(int i = 0; i < n_proce; i++) {
		TAT[i] = wait_t[i] - b_time[i];
		avg_tat += TAT[i];
		avg_wt += wait_t[i]; 
	}

	for(int i = 0 ; i < n_proce; i++) {
		printf("\n P[%d]\t%d\t%d\t%d\t",i + 1, b_time[i], wait_t[i], TAT[i]);
	}

	printf("\nGantt Chart\n");
	for(int i = 0; i < index; i++) {
		printf(" ------ ");
	}
	printf("\n");
	for(int i = 0; i < index; i++) {
		printf("| P[%d]\t",gantt[i] + 1);
	}
	printf("|\n");
	
	for(int i = 0; i < index; i++) {
		printf(" ------ ");
	}
	printf("\n");
	for(int i = 0; i <= index; i++) {
		printf("%d\t",gant_time[i]);
	}
	printf("\n");
}