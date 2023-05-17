#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 50

typedef struct {
	int data[MaxSize];
	int top;
}SqStack;

void stack_init(SqStack* pstack);
void stack_push(SqStack* pstack, int val);
int stack_pop(SqStack* pstack);
int stack_peek(SqStack stack);
bool stack_empty(SqStack stack);