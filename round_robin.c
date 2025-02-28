#include<stdio.h> 




void main() {
	int n, t_quant, flag = 0;
	int total = 0; // total time
	int time_index = 0; // Track number of entries in Gantt chart
	float avgwt = 0, avgtat = 0;
	
	int time_line[100];
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	struct process {
		int id, Bt, Wt, Tat , tBt;
	} p[n];
	
	for (int i = 0; i < n; i++) {
	
		printf("Enter the process ID and Burst Time of P-%d: ",i)
		scanf("%d%d", &p[i].id, &p[i].Bt);
		p[i].tBt = p[i].Bt;
		p[i].Wt = 0;
		p[i].TAt = 0;
	}
	
	printf("\nEnter the time quantum: ");
	scanf("%d",&t_quant);
	
	while(flag != n) {
		for(int i = 0; i < n; i++) {
			if(p[i].tBt > t_quant) {
				for(int j = 0; j < t_quant; j++) {
					timel_line[time_index++] = p[i].id
				}
				total += t_quant;
				p[i].tBt -= t_quant;
			}
			else if(p[i].rt > 0) {
				for(int j = 0; j < p[i].tBt; j++) {
					time_line[time_index++] = p[i].id;
				}
				total += p[i].tBt;
				p[i].tBt = 0;
				p[i].Tat = total
				p[i].Wt = total - p[i].bt;
				flag++;
			}
		}
	}
	
	printf("\nProcess ID\tBurst Time\tWaiting Time\tTurn Around Time");
	for() {
		
	}
}
