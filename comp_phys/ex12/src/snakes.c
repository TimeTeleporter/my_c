#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

int initial_seed = 127;
int boundry = 8191;
int last_gen = 1;
int generator_var = 85;
int random();

int dice(int num_faces);

int board_size = 100;
int* board;
void set_board();
void ladder(int pos, int jump);
void snake(int pos, int fall);

int max_turns = 136;
int snakes_turns();

int main() {
    board = (int*) calloc(board_size+13, sizeof(int));
    set_board();

    int num_games = 1E4;
    int* turns_ary = (int*) calloc (max_turns, sizeof(int));
    float mean = 0.;
    float old_mean = 0.;
    float var = 0.;

    int games = 0;
    while(games<num_games) {
        games++;
        int turn = snakes_turns();
        turns_ary[turn] = turns_ary[turn] +1;
        old_mean = mean;
        mean = (mean*(games-1)+turn)/((float) games);
        if(games > 1) {
            var = (var*(games-2)+(turn-mean)*(turn-old_mean))/((float) games-1);
        }
    }

    for(int i = 0; i<max_turns; i++) printf("%5d ", i);
    printf("\n");
    for(int i = 0; i<max_turns; i++) printf("%5d ", turns_ary[i]);
    printf("\n Trials: %d, Mean: %f, Std: %f\n", num_games, mean, sqrtf(var));

    for(int i = 0; i<max_turns; i++) {
        if(turns_ary[i]) {
            int min = i;
            int min_times = turns_ary[i];
            printf("Min: %d (%d times, p = %f), ", min, min_times, ((float) min_times)/((float) num_games));
            break;
        }
    }

    for(int i = 1; i<max_turns; i++) {
        if(turns_ary[max_turns-i]) {
            int max = max_turns-i;
            int max_times = turns_ary[max_turns-i];
            printf("Max: %d (%d times, p = %f)\n", max, max_times, ((float) max_times)/((float) num_games));
            break;
        }
    }

    free(board);
    free(turns_ary);
    return 0;
}

/*RNG given by the exercise with x_i = (ax_(i-1))mod(2**13 -1)*/
int random() {
    /*
    last_gen = (generator_var*last_gen)%boundry;
    return last_gen;*/
    return rand();
}

int dice(int num_faces) {
    return (random()%num_faces) +1;
}

void set_board() {
    ladder(1, 38);
    ladder(4, 14);
    ladder(9,31);
    snake(17, 7);
    ladder(21, 48);
    ladder(28, 84);
    ladder(51, 67);
    snake(54, 34);
    snake(62, 19);
    snake(64, 60);
    ladder(71, 91);
    ladder(80, 100);
    snake(87, 24);
    snake(93, 73);
    snake(95, 75);
    snake(98, 79);
    return;    
}
void ladder(int pos, int jump) {
    board[pos] = jump-pos;
    return;
}
void snake(int pos, int fall) {
    board[pos] = fall-pos;
    return;
}

int snakes_turns() {
    int pos = 0;
    int turn = 0;
    while(pos < board_size) {
        turn++;
        int throw = dice(6) + dice(6);
        pos = pos + throw + board[pos + throw];
    }
    if(turn < max_turns) {
        return turn;
    }
    else {
        return max_turns-1;
    }
    
}