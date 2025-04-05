#include<stdio.h> 

void main() {
    int n_page;
    int n_frames;
    int hit = 0;
    int fault = 0;

    printf("Enter no. of page request: ");
    scanf("%d",&n_page);
    printf("Enter no. of frames: ");
    scanf("%d",&n_frames);

    int req[n_page];
    int frames[n_frames];
    int frequency[n_frames];

    printf("Enter request : ");
    for(int a = 0; a < n_page; a++) {
        scanf("%d",&req[a]);
    }

    // Initializing the frames and frequency array
    for(int i = 0; i < n_frames; i++) {
        frames[i] = -1;
        frequency[i] = 0;
    }

    printf("------ Page Replacement ------\n");

    for(int i = 0; i < n_page; i ++) {
        int avail = 0;
        printf("\t%d : ",req[i]);

        for(int a = 0; a < n_frames; a++) {
            if(frames[a] == req[i]) {
                avail = 1;
                frequency[a]++;
                hit++;
                break;
            }
        }

        if(avail == 0) {
            int min_freq = frequency[0];
            int min_index = 0; 
            
            // Finding the smallest frequency index
            for(int j = 0; j < n_frames; j++) {
                if(frequency[j] < min_freq) {
                    min_freq = frequency[j];
                    min_index = j;
                }
            }

            // Replacing minimum frequency page
            frames[min_index] = req[i];
            frequency[min_index] = 1;
            fault++;

            // Printing Pages
            for(int j = 0; j < n_frames; j++) {
                if(frames[j] != -1) {
                    printf(" %d ",frames[j]);
                }
                else {
                    printf(" - ");
                }
            }

        }
        else {
            printf("- HIT -");
        }
        printf("\n");
    }
    printf("Hit -> %d\nMiss -> %d\n",hit,fault);
}