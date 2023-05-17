#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INIT_CAPACITY 8
#define THRESHOLD 1024

typedef struct {
	int* data;
	int top;
	int capacity;
}SqStack;

void stack_init(SqStack* pstack);
void stack_push(SqStack* pstack, int val);
int stack_pop(SqStack* pstack);
int stack_peek(SqStack stack);
bool stack_empty(SqStack stack);
void stack_expend(SqStack* pstack);
void stack_destroy(SqStack* ptsack);