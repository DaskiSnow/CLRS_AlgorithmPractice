#include <stdio.h>
#include <stdlib.h>

typedef int K;

typedef struct tree_node {
	K val;
	struct tree_node* lchild;
	struct tree_node* rchild;
}TreeNode;

typedef struct {
	TreeNode* root;
}BTS;

BTS* bts_create();
void bts_insert(BTS* tree, K val);
TreeNode* bts_search(BTS* tree, K val);
void bts_delete(BTS* tree, K val);
BTS* bts_destroy(BTS* tree);