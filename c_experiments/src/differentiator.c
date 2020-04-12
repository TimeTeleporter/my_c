#include <stdio.h>
#include <stdlib.h>

float Input(float* difference, float* margin);

int main() {
    /*Reads in the tracks given by the tracks.txt file.*/
    FILE* tracks = fopen("./data/tracks.txt", "r");

    if(tracks == NULL) {
        printf("No file anywhere to be seen (in the data directory).");
        return 1;
    }

    int entries = 0;
    fscanf(tracks, "%d", &entries);

    char* names[entries];
    float lengths[entries];

    int i = 0;
    while(feof(tracks) == 0) {
        fscanf(tracks, "%s %f", names+i, lengths+i);
        i++;
    }

    fclose(tracks);

    /* Gives out all the availible tracks */
    for(int i = 0; i<entries; i++) {
        printf("%s %3.1f\n", names+i, lengths[i]);
    }

    float difference = 0.;
    float margin = 0.;
    Input(&difference, &margin);

    float tracksum = 0.;
    int tracks_used[entries];
    for(int i = 0; i<entries; i++) {
        tracks_used[i] = 0;
    }
    int num_tracks = 0
    while

    }
    found:
    

    return 0;
}

float Input(float* difference, float* margin) {
    printf("Enter the difference (mm): ");
    scanf("%f", difference);
    printf("Enter the margin (mm): ");
    scanf("%f", margin);
}