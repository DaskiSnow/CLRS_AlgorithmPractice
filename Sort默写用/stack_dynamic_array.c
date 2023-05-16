#include "stack_dynamic_array.h"

void stack_init(SqStack* pstack) {
	pstack->data = (int*)malloc(sizeof(int) * INIT_CAPACITY);
	pstack->top = -1;
	pstack->capacity = INIT_CAPACITY;
}

void stack_push(SqStack* pstack, int val) {
	if (pstack->top == pstack->capacity - 1) {
		stack_expend(pstack);
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

void stack_expend(SqStack* pstack) {
	int new_capacity;
	if (pstack->capacity < THRESHOLD) {
		new_capacity = (pstack->capacity) << 1;
	}
	else {
		new_capacity = pstack->capacity + (pstack->capacity) >> 1;
	}
	int* tmp = (int*)realloc(pstack->data, sizeof(int) * new_capacity);
	if (!tmp) {
		printf("realloc failed in stack_expend.\n");
		exit(1);
	}
	pstack->data = tmp;
	pstack->capacity = new_capacity;
}

void stack_destroy(SqStack* pstack) {
	free(pstack->data);
	pstack->data = NULL;
}