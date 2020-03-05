#include <stdio.h>

int* read_date() {
    /* Reads in a date from the user and returns a pointer to the int arr[3]. */
    static int date[3] = {0, 0, 0};

    printf("DD.MM.YYYY: ");
    scanf("%d.%d.%d", &date[0], &date[1], &date[2]);

    return date;
}

int is_leap(int year) {
    /* returns 1 if the given year is a leap year, else 0. */
    if((year % 4) == 0) {
        if((year % 100) == 0) {
            if((year % 400) == 0) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int dayoftheyear(int* ptr) {
    /* computing the day of the year for a given DD.MM.YYYY input. */
    int days = *ptr;
    int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /* If its a leap year. */
    if(is_leap(*(ptr+2))) {
        monthdays[1] = 29;
    }

    /* adding for months */
    for(int i=0; i < *(ptr+1)-1; i++) {
        days += monthdays[i];
    }

    return days;
}

int date_cmp(int* ptr1, int* ptr2) {
    /* returns the difference of the first to the second given date.
    Inputs are arrays of form DD.MM.YYYY, output is the number of days the dates differ.  */
    int days1 = dayoftheyear(ptr1);
    int days2 = dayoftheyear(ptr2);

    int diff = days1 - days2;
    int year = 0;

    if(*(ptr1+2) > *(ptr2+2)) {
        year = *(ptr2+2);
        while(year != *(ptr1+2)) {
            diff += 365;
            if (is_leap(year)) {
                diff++;
            }
            year++;
        }
    }
    else if(*(ptr1+2) < *(ptr2+2)) {
        year = *(ptr1+2);
        while(year != *(ptr2+2)) {
            diff -= 365;
            if(is_leap(year)) {
                diff--;
            }
            year++;
        }
    }

    return diff;
}

int main() {
    /* Initializing the days of the week. */
    char* weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int weekdays_size = sizeof(weekdays)/sizeof(*weekdays);

    printf("Enter the date of today. ");
    int* temp = read_date();
    int date1[3] = {*(temp), *(temp+1), *(temp+2)};

    printf("Enter the date to compare to. ");
    temp = read_date();
    int date2[3] = {*(temp), *(temp+1), *(temp+2)};

    int diff = date_cmp(date1, date2);
    if(diff == 0) {
        printf("The dates are equal!\n");
    }
    else {
        printf("The dates are off by %d days.", diff);
    }

    return 0;
}