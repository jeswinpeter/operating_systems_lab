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

    int req[n_request + 1];

    printf("Enter disk requests: ");
    for(int i = 0; i < n_request; i++)  {
        scanf("%d",&req[i]);
    }

    req[n_request] = head;
    n_request++;

    // Sort the disk request using Bubble sort
    // for(int i = 0; i < ; i++) {
    //     for(int j = 0; j < ; j++) {
            
    //     }
    // }
}