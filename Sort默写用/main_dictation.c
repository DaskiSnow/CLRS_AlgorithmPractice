#include "sort_dictation.h"
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

int main(void) {
	int arr[] = { 1,3,5,34,34,13,54,88,952,100,200 };
	//direct_insertion_sort(arr, SIZE(arr));
	//selection_sort(arr,0,SIZE(arr)-1);
	//heap_sort(arr, SIZE(arr));
	merge_sort(arr, 0, SIZE(arr) - 1);
	print_arr(arr, SIZE(arr));
}