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
	// ���Ҳ���λ��(���Ѵ��ڲ�������)
	TreeNode* prev = NULL;
	TreeNode* curr = tree->root;
	int cmp;  // �洢�ȽϽ��

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
	// ����
	TreeNode* new_node = (TreeNode*)calloc(1, sizeof(TreeNode));

	// ��ʼ��
	new_node->val = val;

	// ����
	if (prev == NULL) { // ����ʱΪ����
		tree->root = new_node;
	}
	else { // ����ʱ�ǿ���
		if (cmp < 0) {  // ����Ϊ����
			prev->lchild = new_node;
		}
		else { // ����Ϊ�Һ���
			prev->rchild = new_node;
		}
	}
}

TreeNode* bts_search(BTS* tree, K val) {
	// ���ҽ��λ��
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
	// ���ҽ��λ��
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

	// ��ɾ������������ӣ�ת��Ϊ��Ҷ�ӽ�����һ�����ӽ���ɾ��
	if (curr->lchild && curr->rchild) {
		// Ѱ����ɾ���ĺ������
		TreeNode* successor_parent = curr;
		TreeNode* successor = curr->rchild;
		while (successor->lchild) {
			successor_parent = successor;
			successor = successor->lchild;
		} // successor->lchild == NULL

		// �����������
		curr->val = successor->val;

		// ת��Ϊ�Ժ�������ɾ��
		parent = successor_parent;
		curr = successor;
	}

	// ��ɾ�����1�����ӻ�ΪҶ�ӽ��
	TreeNode* child = curr->rchild ? curr->rchild : curr->lchild;  // һ����ȡ���亢��
	if (parent == NULL) { // ��ɾ���Ϊroot���(�߽�����)
		tree->root = child;
		free(curr);
	}
	else if (curr->val < parent->val) { // ��ɾ���ڵ�Ϊ����
		parent->lchild = child;
		free(curr);
	}
	else { // ��ɾ���Ϊ�ҽ��
		parent->rchild = child;
		free(curr);
	}
}

BTS* bts_destroy(BTS* tree);