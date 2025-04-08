#include<stdio.h>

void main() {
    int n_pages;
    int n_frames;
    int avail;
    int hit = 0; 
    int miss = 0;
    int least_rec;
    int min_time;

    printf("Enter no. of page requests: ");
    scanf("%d",&n_pages);
    printf("Enter no. of Frames: ");
    scanf("%d",&n_frames);

    int frames[n_frames];
    int req[n_pages];
    int last_used[n_frames]; 

    printf("Enter page request: ");
    for(int i = 0; i < n_pages; i++) {
        scanf("%d",&req[i]);
    }

    // Initializing frames and last_used to -1
    for(int a = 0; a < n_frames; a++) {
        frames[a] = -1;
        last_used[a] = -1;
    }

    printf("\n------ Page Replacement ------\n");

    for(int i = 0; i < n_pages; i++) {
        avail = 0;
        least_rec = -1;
        min_time = n_pages;

        printf("\t%d : ",req[i]);

        for(int a = 0; a < n_frames; a++) {
            if(frames[a] == req[i]) {
                avail = 1;
                hit++; 
                last_used[a] = i;
                break;
            }
        }

        if(!avail) {
            miss++;
            int empty = -1;

            // Checking for empty frames
            for(int a = 0; a < n_frames; a++) {
                if(frames[a] == -1) {
                    empty = a;
                    break;
                }
            }

            // Filling empty frame
            if(empty != -1) {
                frames[empty] = req[i];
                last_used[empty] = i;
            }
            // No empty frame condition
            else {  
                // Finding least recently used page    
                for(int a = 0; a < n_frames; a++) {
                    if(last_used[a] < min_time) {
                        min_time = last_used[a];
                        least_rec = a;
                    }
                }
                // Replacing least recently used page
                frames[least_rec] = req[i];
                last_used[least_rec] = i;
            }

            for(int a = 0; a < n_frames; a++) {
                if(frames[a] == -1) {
                    printf(" - ");
                }
                else {
                    printf(" %d ",frames[a]);
                }
            }
        }
        else{
            printf("- HIT -");
        }
        printf("\n");
    }

    printf("\nNo. of Hits -> %d\nNo. of Page Faults -> %d\n",hit,miss);
}
