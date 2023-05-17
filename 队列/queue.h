#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 10

typedef struct {
	int data[N];
	int front;
	int rear;
	int size;
}SqQueue;

SqQueue* queue_create();
void queue_push(SqQueue* q, int val);
int queue_pop(SqQueue* q);
int queue_peek(SqQueue* q);
bool queue_empty(SqQueue* q);
bool queue_full(SqQueue* q);
void queue_destroy(SqQueue* q);