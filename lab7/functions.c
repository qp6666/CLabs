#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int inputInteger() {
	int var;
	int c;
	while (1) {
		while (scanf_s("%d", &var) != 1) {
			printf("Incorrect input, try again: ");
			while ((c = getchar()) != '\n' && c != EOF);
		}
		if ((c = getchar()) != '\n' && c != EOF && c != ' ') {
			printf("Incorrect input, try again: ");
			while ((c = getchar()) != '\n' && c != EOF);
		}
		else {
			return var;
		}
	}
}

int inputIntegerInRange(const int min, const int max) {
	while (1) {
		const int number = inputInteger();
		if (number >= min && number <= max) {
			return number;
		}
		printf("The number must be between %d and %d.\n", min, max);
	}
}

binaryTree* createNode(int value) {
	binaryTree* newNode = malloc(sizeof(binaryTree));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
}

binaryTree* createTree(int current_level, int max_level) {
	if (current_level > max_level) {
		return NULL;
	}

	int value = rand() % 100;
	binaryTree* tree = createNode(value);

	tree->left = createTree(current_level + 1, max_level);
	tree->right = createTree(current_level + 1, max_level);

	return tree;
}

void treeVisualisation(binaryTree* tree, int pos) {
	if (tree) {
		treeVisualisation(tree->right, pos + 3);
		puts("");
		for (int i = 0; i < pos; i++)
			printf(" ");
		printf("%d\n", tree->data);
		treeVisualisation(tree->left, pos + 3);
	}
}

void freeTree(binaryTree* tree) {
	if (!tree) return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
}

int sumOddLevels(binaryTree* tree, int level) {
	if (tree == NULL) return 0;

	int sum = 0;
	if (level % 2 == 1) {
		sum += tree->data;
	}

	sum += sumOddLevels(tree->left, level + 1);
	sum += sumOddLevels(tree->right, level + 1);

	return sum;
}