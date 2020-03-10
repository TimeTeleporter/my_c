#include <stdio.h>

int verbose = 0;

int main(int argc, char* argv[]) {
    if(verbose) printf("No\n");
    verbose = 1;
    if(verbose) printf("Yes\n");
    return 0;
}