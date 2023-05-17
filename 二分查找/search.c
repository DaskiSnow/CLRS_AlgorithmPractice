#include "search.h"

int binary_search(int arr[],int n,int val){
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = (left >> 1) + (right >> 1);
		if (arr[mid] == val) {
			return mid;
		}
		if (val < arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}