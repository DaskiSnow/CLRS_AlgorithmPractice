#include "queue.h"

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