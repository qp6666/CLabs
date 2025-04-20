#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
	int data;
	struct tag_obj* next;
}OBJ;

int inputInteger();

int inputIntegerInRange(const int min, const int max);

OBJ* push(OBJ* top, int data);

void show(const OBJ* top);

int fillStack(int count);

void chooseTask();

void outputLargestElement();

void findMaxElement(const OBJ* top);


