#include <stdio.h>
int main() {
    int frames[10], pages[30], num_frames, num_pages, i, j, k, page_faults = 0, front = 0;
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter page reference string: ");
    for(i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }
    for(i = 0; i < num_pages; i++) {
        int found = 0;
        for(j = 0; j < num_frames; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            frames[front] = pages[i];
            front = (front + 1) % num_frames;
            page_faults++;
        }
        for(k = 0; k < num_frames; k++) {
            if(frames[k] != -1) {
                printf("%d ", frames[k]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", page_faults);
    return 0;
}
