#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct node {
	int val;
	struct node* next;
}Node;

void stack_push(Node** pstack, int val);
int stack_pop(Node** pstack);
int stack_peek(Node* stack);
bool stack_empty(Node* stack);
void stack_destroy(Node** pstack);  //Œ¥ µœ÷