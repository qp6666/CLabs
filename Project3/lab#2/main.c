#include"functions.h"

#include <stdio.h>


int main(int argc,char* argv[]) {
	if (argc < 2) {
		printf("Error!");
		return 1;
	}

	FILE* file = fopen(argv[1], "w");

	puts("Choose number of task(1-3) or exit:");
	int choice = inputIntegerInRange(1, 5);

	puts("Enter number of elements:");
	int size = inputIntegerInRange(1, 100);

	if (choice == 1) {
		writeFile(file, size);

		FILE* file = fopen(argv[1], "r");
		readFromFile(file);

		fclose(file);
	}
	if (choice == 2) {
		writeFile(file, size);

		FILE* file = fopen(argv[1], "r");
		readFromFile(file);
		rewind(file);

		findSumInFile(file);

	}	
	if (choice == 3) {
		writeFile(file, size);

		FILE* file = fopen(argv[1], "r");
		readFromFile(file);
		fclose(file);

		swapLastTwoNumbersInFile(argv[1]);
	}
	else {
		exit(0);
	}
}