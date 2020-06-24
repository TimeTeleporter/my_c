#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

int initial_seed = 127;
int boundry = 8191;
int last_gen = 1;
int random(int generator_var);

void dice(int generator_var, int num_extracts, int num_faces);
void int_histogram(int* array, int array_len);

int period(int generator_var);
int get_period(int generator_var, int seed);

int main() {
    dice(81, 3000, 6);
    dice(83, 3000, 6);
    dice(85, 3000, 6);
    dice(91, 3000, 7);
    return 0;
}

/*RNG given by the exercise with x_i = (ax_(i-1))mod(2**13 -1)*/
int random(int generator_var) {
    last_gen = (generator_var*last_gen)%boundry;
    return last_gen;
}

void dice(int generator_var, int num_extracts, int num_faces) {
    int dicerolls[num_faces];
    for(int i = 0; i<num_faces; i++) dicerolls[i] = 0;

    /* reset the seed for better compairability */
    last_gen = initial_seed;

    int index = 0;
    for(int i = 0; i< num_extracts; i++) {
        index = random(generator_var)%(num_faces +1);
        dicerolls[index] += 1;
    }

    printf("Seed: %d, Generator Variable: %d, Extracts: %d", initial_seed, generator_var, num_extracts);
    int_histogram(dicerolls, num_faces);

    printf("Periode: %d\n\n", period(generator_var));
    
    return;
}

void int_histogram(int* array, int array_len) {
    /* A function to draw a histogram with numbers */
    float sum = 0.;
    for(int i = 0; i<array_len; i++) {
        sum += array[i];
    }
    float avr = 0;
    float var = 0;

    printf("\n Face       |");
    for(int i = 0; i<array_len; i++) printf("%4d |", i+1);
    printf("\n Throws     |");
    for(int i = 0; i<array_len; i++) printf("%4d |", array[i]);
    printf("\n Percentage |");
    for(int i = 0; i<array_len; i++) printf("%4.2f|", (((float) array[i])/sum)*100);
    printf("\n");

    return;
}

int period(int generator_var) {
    get_period(generator_var, initial_seed);
    return get_period(generator_var, last_gen);
}

int get_period(int generator_var, int seed) {
    last_gen = seed;
    int list_size = 1;
    int* list = (int*) malloc(list_size*sizeof(int));
    list[list_size-1] = seed;
    do {
        int new = random(generator_var);
        for(int i = 0; i<list_size; i++){
            if(new == list[i]) {
                return list_size;
            }
        }
        list_size++;
        list = (int*) realloc(list, list_size*sizeof(int));
        list[list_size-1] = new;
    } while(list_size<boundry);

    free(list);
    return 0;
}