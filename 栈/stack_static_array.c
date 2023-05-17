#include "stack_static_array.h"

//int main(void) {
//	SqStack stack;
//	stack_init(&stack);
//	stack_push(&stack, 1);
//	stack_push(&stack, 2);
//	stack_push(&stack, 3);
//	bool empty = stack_empty(stack);
//	int pop_num = stack_pop(&stack);
//	int peek_num = stack_peek(stack);
//	pop_num = stack_pop(&stack);
//	peek_num = stack_peek(stack);
//	pop_num = stack_pop(&stack);
//	empty = stack_empty(stack);
//
//	return 0;
//}

void stack_init(SqStack* pstack) {
	pstack->top = -1;
}

void stack_push(SqStack* pstack, int val) {
	if (pstack->top == MaxSize) {
		printf("Push failed due to stack overflow.\n");
		return;
	}
	pstack->top++;
	pstack->data[pstack->top] = val;
}

int stack_pop(SqStack* pstack) {
	if (pstack->top == -1) {
		printf("Pop failed due to stack empty.\n");
		return;
	}
	return pstack->data[(pstack->top)--];
}

int stack_peek(SqStack stack) {
	if (stack.top == -1) {
		printf("peek failed due to stack empty.\n");
		return;
	}
	return stack.data[stack.top];
}

bool stack_empty(SqStack stack) {
	return stack.top == -1;
}