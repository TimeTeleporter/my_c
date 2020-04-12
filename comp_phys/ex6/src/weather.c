#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int num;
    float avr;
    float var;
} measurement;

void init_measurement(measurement*);
void update_measurement(float, measurement*);

int main() {
    int num_stations = 5; /*0. nothington, 1. bern, 2. zurich, 3. geneva, 4. basel */
    char* stations[] = {"Nothington", "Bern", "Zurich", "Geneva", "Basel"};
    int stations_trials[] = {0, 0, 0, 0, 0};
    measurement tem[num_stations];
    measurement hum[num_stations];
    for(int i = 0; i<num_stations; i++) {
        init_measurement(tem+i);
        init_measurement(hum+i);
    }

    FILE* file = fopen("./data/weather.txt", "r");

    if(file == NULL) {
        printf("No file anywhere to be seen.");
        return 1;
    }

    int trials = 0;
    while(feof(file) == 0) {
        trials++;
        int time = 0;
        int packages = 0;
        fscanf(file, "%d %d", &time, &packages);

        for(int i = 0; i<packages; i++) {
            int station = 0;
            float temperature = 0., humidity = 0.;
            fscanf(file, "%d %f %f", &station, &temperature, &humidity);

            stations_trials[i] += 1;
            update_measurement(temperature, tem+station);
            update_measurement(humidity, hum+station);
        }
    }
    
    fclose(file);

    for(int i = 1; i<num_stations; i++) {
        printf("%s: average temperature: %f pm %f, average rel. humidity: %f pm %f.\n", stations[i], tem[i].avr, sqrtf(tem[i].var), hum[i].avr, sqrtf(hum[i].var));
        printf("%s had an %3.1f efficiency.\n", stations[i], stations_trials[i]*100/trials);
    }

    return 0;
}

void init_measurement(measurement* ptr) {
    ptr->num = 0;
    ptr->avr = 0.;
    ptr->var = 0.;
}

void update_measurement(float value, measurement* data) {
    int N = data->num;
    data->num = ++N;

    float old_avr = data->avr;
    float old_var = data->var;

    float new_avr = (old_avr*(N-1)+value)/N;
    data->avr = new_avr;

    if(N != 1) {
        data->var = (N-2)*old_var/(N-1)+(value-new_avr)*(value-old_avr)/(N-1);
    }

    return;
}