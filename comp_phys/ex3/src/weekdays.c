#include <stdio.h>

int main() {
    /* Initializing the days of the week. */
    char* weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int weekdays_size = sizeof(weekdays)/sizeof(*weekdays);

    printf("Today its %s!\n", weekdays[3]);

    return 0;
}