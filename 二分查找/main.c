#include <stdio.h>
#include "search.h"
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int main(void) {
	int arr[] = { 1,5,7,8,34,36,44 };
	int idx = binary_search(arr, SIZE(arr), 34);

	return 0;
}