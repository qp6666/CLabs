#include "functions.h"
#include "sorting.h"

void task4() {
	FILE* my_file = openFile("w+b");

	fillFileManually(my_file);

	puts("Your numbers are:\n");
	printFile(my_file);

	sortFile(my_file);

	puts("Numbers in sorted file are:\n");
	printFile(my_file);

	fclose(my_file);
}