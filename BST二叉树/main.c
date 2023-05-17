#include "bst.h"

int main(void) {
	BTS* tree = bts_create();
	bts_insert(tree, 9);
	bts_insert(tree, 5);
	bts_insert(tree, 42);
	bts_insert(tree, 3);
	bts_insert(tree, 13);
	bts_insert(tree, 57);

	bts_delete(tree, 5);
	TreeNode* search_node=bts_search(tree, 42);
	return 0;
}