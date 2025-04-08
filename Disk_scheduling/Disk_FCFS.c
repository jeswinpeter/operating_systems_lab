#include<stdio.h> 

void main() {
    int head;
    int n_request;
    int distance;
    int seektime = 0;
    
    printf("Enter head position: ");
    scanf("%d",&head);
    printf("Enter no. of disk request: ");
    scanf("%d",&n_request);

    int req[n_request];

    printf("Enter disk requests: ");
    for(int i = 1; i <= n_request; i++)  {
        scanf("%d",&req[i]);
    }

    req[0] = head;
    
    printf("\n---- FCFS Disk scheduling ----\n");
    printf("\t--- Movement ---\t--- Seektime ---\n");
    for(int i = 0; i < n_request; i++) {
        distance = (req[i] > req[i + 1]) ? (req[i] - req[i + 1]) : (req[i + 1] - req[i]);
        printf("Disk movement from %d to %d :\t\t%d\n", req[i], req[i + 1], distance);
        seektime += distance; 
    }

    printf("Total seek time -> %d\n",seektime);

}