#include "bst.h"

int main(void) {
	BST* tree = bst_create();
	bst_insert(tree, 9);
	bst_insert(tree, 5);
	bst_insert(tree, 42);
	bst_insert(tree, 3);
	bst_insert(tree, 13);
	bst_insert(tree, 57);

	TreeNode* search_node=bst_search(tree, 42);
	bst_inorder(tree);
	bst_preorder(tree);
	bst_postorder(tree);
	
	bst_destroy(tree);

	return 0;
}