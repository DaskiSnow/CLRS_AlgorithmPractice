#include "bst.h"

BTS* bts_create() {
	BTS* tree = (BTS*)calloc(1, sizeof(BTS));
	if (!tree) {
		printf("calloc failed in bts_create.\n");
		exit(1);
	}
	return tree;
}

void bts_insert(BTS* tree, K val) {
	// 查找插入位置(若已存在不做处理)
	TreeNode* prev = NULL;
	TreeNode* curr = tree->root;
	int cmp;  // 存储比较结果

	while (curr) {
		cmp = val - curr->val;
		if (cmp == 0) return;
		if (cmp < 0) {
			prev = curr;
			curr = curr->lchild;
		}
		else {
			prev = curr;
			curr = curr->rchild;
		}
	}// curr == NULL


	// (curr == NULL)
	// 创建
	TreeNode* new_node = (TreeNode*)calloc(1, sizeof(TreeNode));

	// 初始化
	new_node->val = val;

	// 插入
	if (prev == NULL) { // 插入时为空树
		tree->root = new_node;
	}
	else { // 插入时非空树
		if (cmp < 0) {  // 插入为左孩子
			prev->lchild = new_node;
		}
		else { // 插入为右孩子
			prev->rchild = new_node;
		}
	}
}

TreeNode* bts_search(BTS* tree, K val) {
	// 查找结点位置
	TreeNode* curr = tree->root;
	int cmp;
	while (curr) {
		cmp = val - curr->val;
		if (cmp == 0) {
			return curr;
		}
		if (cmp < 0) {
			curr = curr->lchild;
		}
		else {
			curr = curr->rchild;
		}
	}// curr == NULL

	return NULL;
}

void bts_delete(BTS* tree, K val) {
	// 查找结点位置
	TreeNode* parent = NULL;
	TreeNode* curr = tree->root;
	int cmp;
	while (curr) {
		cmp = val - curr->val;
		if (cmp == 0) {
			break;
		}
		if (cmp < 0) {
			parent = curr;
			curr = curr->lchild;
		}
		else {
			parent = curr;
			curr = curr->rchild;
		}
	}// cmp == 0 || curr == NULL
	
	if (curr == NULL) return;

	// 欲删结点有两个孩子，转化为对叶子结点或有一个孩子结点的删除
	if (curr->lchild && curr->rchild) {
		// 寻找欲删结点的后驱结点
		TreeNode* successor_parent = curr;
		TreeNode* successor = curr->rchild;
		while (successor->lchild) {
			successor_parent = successor;
			successor = successor->lchild;
		} // successor->lchild == NULL

		// 交换结点数据
		curr->val = successor->val;

		// 转化为对后驱结点的删除
		parent = successor_parent;
		curr = successor;
	}

	// 欲删结点有1个孩子或为叶子结点
	TreeNode* child = curr->rchild ? curr->rchild : curr->lchild;  // 一起处理取得其孩子
	if (parent == NULL) { // 欲删结点为root结点(边界条件)
		tree->root = child;
		free(curr);
	}
	else if (curr->val < parent->val) { // 欲删除节点为左结点
		parent->lchild = child;
		free(curr);
	}
	else { // 欲删结点为右结点
		parent->rchild = child;
		free(curr);
	}
}

BTS* bts_destroy(BTS* tree);