#include<stdio.h>

int main() {
    int p_request;
    int p_frames;
    int hits = 0;
    int fault = 0;
    int j = 0;

    printf("Enter the no. of page request: ");
    scanf("%d",&p_request);
    printf("Enter the no. of page frames: ");
    scanf("%d",&p_frames);

    int frames[p_frames], req[p_request];

    printf("Enter page requests: ");    
    for(int i = 0; i < p_request; i++) {
        scanf("%d",&req[i]);
    }

    for(int a = 0; a < p_frames; a++) {
        frames[a] = -1;
    }

    printf("------ Page Repacement ------\n");

    for(int i = 0; i < p_request; i++) {
        int avail = 0;

        printf("\t%d : ", req[i]);
        
        for(int a = 0; a < p_frames; a++) {
            if(frames[a] == req[i]) {
                avail = 1;
                hits++;
                break;
            }
        }

        if(avail == 0) {
            frames[j] = req[i];
            j = (j + 1) % p_frames;
            fault++;
        }   

        if(avail == 1) {
            printf("- Hit -\n");
        }
        else {
            for(int a = 0; a < p_frames; a++) {
                if(frames[a] == -1) {       //Empty frames
                    printf("- ");
                }
                else {
                    printf("%d ",frames[a]);
                }
            }
            printf("\n");
        }
    }

    printf("------------------------------\nNumber of page faults -> %d\n",fault);
    printf("Number of hits -> %d\n",hits);
}