#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree() {
	BSTree tree = NULL;
	return tree;
}

void AddNode(BSTree *bst, char *word) {

	if (*bst == NULL) {

		*bst = (BSTree)malloc(sizeof(Node));
		(*bst)->left = NULL;
		(*bst)->right = NULL;
		(*bst)->word = word;

	} else {
		if (!strcmp(word, (*bst)->word)) {

			free(word);

		} else if (strcmp(word, (*bst)->word) < 0) {

			AddNode((&(*bst)->left), word);

		} else if (strcmp(word, (*bst)->word) > 0) {

			AddNode((&(*bst)->right), word);

		}
	}
}

int BSTHeight(BSTree bst) {

	int max_left = 0;
	int max_right = 0;

	if (bst == NULL) {
		return 0;
	}

	if (bst->left != NULL) {
		max_left = BSTHeight(bst->left);
	}

	if (bst->right != NULL) {
		max_right = BSTHeight(bst->right);
	}

	return max_left > max_right ? max_left + 1 : max_right + 1;
}

void PrintBSTree(BSTree bst) {

	if (bst == NULL) {
		return;
	}

	PrintBSTree(bst->left);

	printf("%s\n", bst->word);

	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd) {

	if (bst == NULL) {
		return;
	}

	fprintf(fd, "%s ", bst->word);

	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst) {

	if (bst == NULL) {
		return;
	}

	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);

	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE* fd) {

	BSTree tree = NewBSTree();
	char word[32];

	while (fscanf_s(fd, "%s", word) != EOF) {
		AddNode(&tree, _strdup(word));
	}

	return tree;
}
