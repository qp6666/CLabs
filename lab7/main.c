#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
	srand(time(NULL));

	puts("Enter number of levels in tree:\n");
	int number_of_levels = inputIntegerInRange(1, 10);
	binaryTree* tree = createTree(1, number_of_levels);

	puts("Your tree:\n");
	treeVisualisation(tree, 0);

	puts("Sum:\n");
	int sum = sumOddLevels(tree, 0);
	printf("%d", sum);
	freeTree(tree);
	return 0;
}