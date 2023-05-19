#include <stdio.h>
#include "search.h"
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int main(void) {
	int arr[] = { 1,4,4,4,4,7,8,8};
	//int idx = binary_search_first_e(arr, SIZE(arr), -1);
	int idx = binary_search4(arr, SIZE(arr), 5);
	printf("%d", idx);
	return 0;
}