#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct node{
	int val;
	struct node* next;
}Node;

void stack_push(Node** pstack, int val);
int stack_pop(Node** pstack);
int stack_peek(Node* stack);
bool stack_empty(Node* stack);
void stack_destroy(Node** pstack);  //未实现

int main(void) {
	Node* stack=NULL;//一定要初始化为NULL
	stack_push(&stack, 1);
	stack_push(&stack, 2);
	stack_push(&stack, 3);
	bool empty=stack_empty(stack);
	int peek_num=stack_peek(stack);
	int pop_num = stack_pop(&stack);
	pop_num = stack_pop(&stack);
	peek_num = stack_peek(stack);
	pop_num = stack_pop(&stack);
	empty = stack_empty(stack);

	return 0;
}

void stack_push(Node** pstack, int val) {
	Node* pnode = (Node*)malloc(sizeof(Node));
	if (!pnode) {
		printf("malloc failed in stack_push.\n");
		exit(1);
	}
	pnode->val = val;
	pnode->next = *pstack;
	*pstack = pnode;
}

int stack_pop(Node** pstack) {
	if (*pstack == NULL) {
		printf("stack is null.\n");
		return -1;//假设元素都是非零数
	}
	Node* p = *pstack;
	int res = p->val;
	*pstack = p->next;
	free(p);
	return res;
}

int stack_peek(Node* stack) {
	if (stack == NULL) {
		printf("stack is null.\n");
		return -1;
	}
	return stack->val;
}

bool stack_empty(Node* stack) {
	return !((bool)stack);
}