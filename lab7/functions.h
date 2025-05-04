#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree {
	int data;
	struct binaryTree* right;
	struct binaryTree* left;
}binaryTree;

int inputInteger();

int inputIntegerInRange(const int min, const int max);

binaryTree* createNode(int value);

binaryTree* createTree(int current_level, int max_level);

void printTree(binaryTree* root, int space);

void freeTree(binaryTree* root);

void treeVisualisation(binaryTree* root, int pos);

int sumOddLevels(binaryTree* tree, int level);