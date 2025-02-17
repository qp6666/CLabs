#include "functions.h"

#include <stdio.h>


int calculateCountOfSmallerNumbers(FILE* file) {
	const int reference_const = inputIntegerInRange(-100, 100);
	int count_of_numbers = 0;

	for (int i = 0; i < calculateFileLength(file); i++) {
		if (getNumber(file, i) < reference_const) {
			++count_of_numbers;
		}
	}
	return count_of_numbers;
}


void task2(){
	FILE* my_file = openFile("w+b");

	fillFileManually(my_file);

	puts("Your numbers are:\n");
	printFile(my_file);

	printf("\nThe quantity of numbers is less than the specified one = %d\n", calculateCountOfSmallerNumbers(my_file));

	fclose(my_file);
}