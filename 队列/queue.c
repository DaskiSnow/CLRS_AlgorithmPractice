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
void queue_push(SqQueue* q,int val);
int queue_pop(SqQueue* q);
int queue_peek(SqQueue* q);
bool queue_empty(SqQueue* q);
bool queue_full(SqQueue* q);
void queue_destroy(SqQueue* q);

int main(void) {
	SqQueue* q = queue_create();
	for (int i = 0; i < 10; i++) {
		queue_push(q, i);
	}
	int pop_num, peek_num;
	bool empty, full;
	empty = queue_empty(q);
	full = queue_full(q);
	pop_num=queue_pop(q);
	peek_num = queue_peek(q);
	pop_num = queue_pop(q);
	full = queue_full(q);


}

SqQueue* queue_create() {
	SqQueue* q = (SqQueue*)malloc(sizeof(SqQueue));
	if (!q) {
		printf("malloc failed in queue_create.\n");
		exit(1);
	}
	q->front = 0;
	q->rear = 0;  //rear指向可以存储的位置
	q->size = 0;
	return q;
}

void queue_push(SqQueue* q, int val) {
	if (q->size == N) {
		printf("Push failed due to queue full.\n");
		exit(1);
	}
	q->data[q->rear]=val;
	q->rear = (q->rear + 1) % N;
	q->size++;
}

int queue_pop(SqQueue* q) {
	if (q->size == 0) {
		printf("Pop failed due to queue empty.\n");
		exit(1);
	}
	int pop_num = q->data[q->front];
	q->front = (q->front + 1) % N;
	q->size--;
	return pop_num;
}

int queue_peek(SqQueue* q) {
	if (q->size == 0) {
		printf("Peek failed due to queue empty.\n");
		exit(1);
	}
	return q->data[q->front];
}
bool queue_empty(SqQueue* q) {
	return q->size == 0;
}

bool queue_full(SqQueue* q) {
	return q->size == N;
}

void queue_destroy(SqQueue* q) {
	free(q);
	q = NULL;
}