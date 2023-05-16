#include<stdio.h>
#include "sort.c"
#define SIZE(x) (sizeof(x) / sizeof(x[0]))

int main(void) {
	int arr[] = { 2,24,6,100,24,55,678,5674,24,100 };
	shell_sort(arr, SIZE(arr));
	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}

}