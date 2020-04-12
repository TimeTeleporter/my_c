#include <stdio.h>
#include <stdlib.h>

int sort(char** names, char** names_sorted, float* lengths, float* lengts_sorted, int entries);

int main() {
    char* names[] = {"00000", "24064", "24071","24077","24094","24172", "24188", "24236", "24360"};
    float lengths[] = {0.0, 64.3, 70.8, 77.5, 94.2, 171.7, 188.3, 236.1, 360.0};
    int entries = sizeof(lengths)/sizeof(*lengths);

    FILE* tracks = fopen("./data/tracks.txt", "w");

    fprintf(tracks, "%d", entries);

    for(int i = 0; i<entries; i++) {
        fprintf(tracks, "\n");
        fprintf(tracks, "%s %3.1f", names[i], lengths[i]);
    }

    fclose(tracks);
    return 0;
}
