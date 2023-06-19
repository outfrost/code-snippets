#include <stdlib.h>
#include <stdio.h>

/*struct BST;*/

struct BST {
	long val;
	struct BST* parent;
	struct BST* left;
	struct BST* right;
};

typedef struct BST BST;

/*typedef struct {
	long val;
	BST* parent;
	BST* left;
	BST* right;
} BST;*/

BST* create_bst(const long a[], size_t length) {
	BST* tree = NULL;
	BST* current;
	BST* parent;
	BST** insertion_ptr;
	for (size_t i = 0; i < length; ++i) {
		current = tree;
		parent = NULL;
		insertion_ptr = &tree;
		while (current != NULL) {
			parent = current;
			if (a[i] <= (*current).val) {
				current = (*current).left;
				insertion_ptr = &(*parent).left;
			}
			else {
				current = (*current).right;
				insertion_ptr = &(*parent).right;
			}
		}
		current = malloc(sizeof(BST));
		(*current).val = a[i];
		(*current).parent = parent;
		(*insertion_ptr) = current;
	}
	return tree;
}

void print_bst_node(BST* node) {
	if (node != NULL) {
		printf("{ %ld", (*node).val);
		if ((*node).parent != NULL) {
			printf(", parent: %ld", (*(*node).parent).val);
		}
		if ((*node).left != NULL) {
			printf(", left: %ld", (*(*node).left).val);
		}
		if ((*node).right != NULL) {
			printf(", right: %ld", (*(*node).right).val);
		}
		printf(" }\n");
	}
	else {
		printf("{ [nullptr] }\n");
	}
}

void print_bst(BST* tree) {
	if (tree != NULL && (*tree).left != NULL) {
		print_bst((*tree).left);
	}
	print_bst_node(tree);
	if (tree != NULL && (*tree).right != NULL) {
		print_bst((*tree).right);
	}
}

int main(int argc, char** argv) {
	long ary[] = { 2, 19, 4, 7, -12, 17, 0, 24, 8 };
	BST* tree = create_bst(ary, 9);
	print_bst(tree);
	return 0;
}
