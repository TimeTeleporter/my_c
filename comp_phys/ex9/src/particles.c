#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned short time;
    unsigned char Y;
    unsigned char X;
} particle;

void particle_entry(particle*, int*);
void particle_print(particle);

int main() {
    /* Initializing */
    int unsigned array_size = 16, index = 0;
    particle* array = (particle*) malloc(array_size*sizeof(particle));

    /* File read */
    FILE* file = fopen("./data/det_data.txt", "r");

    if(file == NULL) {
        printf("No file anywhere to be seen.");
        return 1;
    }

    while(foef(file) == 0) {
        if(index == array_size) {
            array_size = array_size*2;
            array = (particle*) realloc(array, array_size*sizeof(particle));
        }

        unsigned int* ptr;
        fscanf(file, "%u", ptr);

        particle_entry(array+index, ptr);

        index++;
    }

    /* Logic */
    for(int i = 0; i<index; i++) {
        
    }

    for()

    free(array);
    return 0;
}

void particle_entry(particle* ary, int* ptr) {
    ary->time = *(((short*) ptr)+1);
    ary->Y = *(((char*) ptr)+1);
    ary->X = *((char*) ptr);
}

void particle_entry_TEST() {
    particle hui;
    unsigned int a = 299485560;
    particle_entry(&hui, &a);
    particle_print(hui);
}

void particle_print(particle obj) {
    printf("X: %hhu Y: %hhu time: %hu", obj.X, obj.Y, obj.time);
}