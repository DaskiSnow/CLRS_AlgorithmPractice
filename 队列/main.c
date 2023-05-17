#include "queue.h"

int main(void) {
	SqQueue* q = queue_create();
	for (int i = 0; i < 10; i++) {
		queue_push(q, i);
	}
	int pop_num, peek_num;
	bool empty, full;
	empty = queue_empty(q);
	full = queue_full(q);
	pop_num = queue_pop(q);
	peek_num = queue_peek(q);
	pop_num = queue_pop(q);
	full = queue_full(q);


}