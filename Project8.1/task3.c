#include "functions.h"

#include <stdio.h>





void task3() {
	FILE* my_file = openFile("w+b");

	fillFileManually(my_file);

	puts("Your numbers are:\n");
	printFile(my_file);

	fclose(my_file);
}