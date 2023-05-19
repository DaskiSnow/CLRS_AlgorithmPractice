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

int binary_search_first_e(int arr[], int n, int val) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left  + (right-left >> 1);
		if (val <= arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (arr[left] == val) return left;
	return -1;
}

int binary_search_first_e_2(int arr[], int n, int val) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (val < arr[mid]) {
			right = mid - 1;
		}
		else if(val > arr[mid]) {
			left = mid + 1;
		}
		else{
			
		}
	}
	return -1;
}



int binary_search_last_e(int arr[], int n, int val) {

}

int binary_search_first_ge(int arr[], int n, int val) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (val <= arr[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (arr[left] < val) return -1;
	return left;
}

int binary_search_last_le(int arr[], int n, int val) {
	
}

// 查找第一个与 key 相等的元素
int binary_search1(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
		else {
			if (mid == left || arr[mid - 1] < key) {
				return mid;
			}
				right = mid - 1;
		}
	} // left > right

	return -1;
}

// 查找最后一个与 key 相等的元素
int binary_search2(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else if (key > arr[mid]) {
			left = mid + 1;
		}
		else {
			if (mid == right || arr[mid + 1] > key) {
				return mid;
			}
			left = mid + 1;
		}
	} // left > right

	return -1;
}

// 查找第一个大于等于 key 值的元素
int binary_search3(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (key > arr[mid]) {
			left = mid + 1;
		}
		else { // key <= arr[mid]
			if (mid == left || arr[mid - 1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	} // left > right

	return -1;
}


// 查找最后一个小于等于 key 值的元素
int binary_search4(int arr[], int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left >> 1);
		if (key < arr[mid]) {
			right = mid - 1;
		}
		else { // key == arr[mid] || key > arr[mid]
			if (mid == right || arr[mid + 1] > key) {
				return mid;
			}
			left = mid + 1;
		}
	}

	return -1;
}