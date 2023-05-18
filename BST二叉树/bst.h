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
}BST;

BST* bst_create();
void bst_destroy(BST* tree);
void bst_insert(BST* tree, K val);
TreeNode* bst_search(BST* tree, K val);
void bst_delete(BST* tree, K val);
void bst_preorder(BST* tree);
void bst_inorder(BST* tree);
void bst_postorder(BST* tree);