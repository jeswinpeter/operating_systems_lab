#include<stdio.h>

void main() {
    int res,pros;
    printf("Enter Number of resources: \n");
    scanf("%d",&res);
    printf("Enter number of processes: \n");
    scanf("%d",&pros);
    int max[pros][res];
    int need[pros][res];
    int alloc[pros][res];
    int work[res];
    int finish[pros];
    int safe_seq[pros];
    int flag = 0;
    int count = 0;

    for(int i = 0; i < pros; i++) {
        finish[i] = 0;
    }

    printf("Enter Allocation matrix: \n");
    for(int i = 0; i < pros; i++) {
        for(int j = 0; j < res; j++) {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter Max matrix: \n");
    for(int i = 0; i < pros; i++) {
        for(int j = 0; j < res; j++) {
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter available matrix: \n");
    for(int i = 0; i < res; i++) {
        scanf("%d",&work[i]);
    }

    //Creating Need matrix
    for(int i = 0; i < pros; i++) {
        for(int j = 0; j < res; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Main Bankers loops
    for(int i = 0; i < pros; i++){
        for(int j = 0; j < pros; j++) {
            if(finish[j] == 0) {
                flag = 0;
                for(int k = 0; k < res; k++) {
                    if(need[j][k] > work[k]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    for(int m = 0; m < res; m++) {
                        work[m] += alloc[j][m];
                    }
                    finish[j] = 1;
                    safe_seq[count++] = j + 1;
                }
            }
        }
    }

    if(count == pros) {
        printf("\nThe Safe sequence is: \n");
        for (int i = 0; i < pros; i++) {
            printf("P%d\t",safe_seq[i]);
        }
    }
    else {
        printf("!!! No Safe Sequence Available!!!");
    }
}