#include<stdio.h>

int main() {
    int p_request;
    int p_frames;
    int hits;
    int fault;

    printf("Enter the no. of page request: ");
    scanf("%d",&p_request);
    printf("Enter the no. of page frames: ");
    scanf("%d",&p_frames);
    printf("Enter the no. of page request: ");

    int frames[p_frames], request[p_request];

    printf("Enter page requests: ");    
    for(int i = 0; i < p_request; i++) {
        scanf("%d",&request[i]);
        if(i < p_frames) {
            frames[i] = -1;
        }
    }

    printf("------- Page Repacement ---------");

    for(int i = 0; i < p_request; i++) {
        int avail = 0;

        printf("%d : ", request[i]);
        
        for(int a = 0; a < p_frames; a++) {
            if(frames[a] = request[i]) {
                avail = 1;
                hits++;
                break;
            }
        }

        if(avail = 0) {
            frames[j] = request[i];
            j = (j + 1) % p_frames;
            fault++;
        }   

        if(avail = 1) {
            printf("- Hit -");
        }
        else {
            for(int a = 0; a < p_frames; a++) {
                if(frames[a] == -1) {
                    printf(" - ")
                }
            }
        }
    }

}