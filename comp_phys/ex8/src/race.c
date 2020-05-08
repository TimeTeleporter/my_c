#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { 
    unsigned int date;
    char firstname[30];
    char lastname[30];
    unsigned int year;
    char nation[30];
    float time;
    float wind;
} Record;

int main() {
    FILE* file = fopen("./data/records.txt", "r");
    
    int runner = 0;

    int array_size = 4;
    Record* array = (Record*) malloc(sizeof(Record)*array_size);
    Record* temp_array;

    while(feof(file) == 0) {
        if(runner+1 == array_size) {
            temp_array = array;

        }
    }

    free(array);
    free(temp_array);

    return 0;
}