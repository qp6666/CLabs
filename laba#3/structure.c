#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bitField {
    unsigned value : 32;
};


struct Date {
    char release_date[20];
};


struct Series {
    int episodes;
    char* title;
    struct Date date;
    int seasons;
};