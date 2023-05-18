#include "sort_dictation.h"
#include "stack_dynamic_array.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void direct_insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = arr[i]; //保存待插入元素
		int j;
		for (j = i-1; j >= 0; j--) {
			if (arr[j] <= tmp) {
				break;
			}
			arr[j + 1] = arr[j];// 边找边移动元素
		}// arr[j] <= tmp, 应插入到j+1位置
		arr[j + 1] = tmp;
	}
}

void binary_insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int tmp = arr[i];
		int low = 0;
		int high = i-1;
		while (low <= high) {  //注意有等号
			int mid = (low + high) / 2;
			if (tmp < arr[mid]) {
				high = mid - 1;
			}
			else {  // tmp >= arr[mid],保证了稳定性
				low = mid + 1;
			}
		}// low > high, 应插入到low位置

		//移动元素
		for (int k = i; k >= low + 1; k--) {
			arr[k] = arr[k - 1];
		}
		arr[low] = tmp;
	}
}

void shell_sort(int arr[], int n) {
	int gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i ++) {
			int tmp = arr[i];
			int j;
			for (j = i - gap; j >= 0 && arr[j]>tmp; j-=gap) {
				arr[j + gap] = arr[j]; // 移动元素
			}// arr[j] <= tmp, 应插入到j+gap的位置
			arr[j + gap] = tmp;
		}
	}
}

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= n - 2 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= pivot) high--;
		arr[low] = arr[high];
		while (low < high && arr[low] <= pivot) low++;
		arr[high] = arr[low];
	} // low == high
	arr[low] = pivot;
	return low;
}

void quick_sort(int arr[], int low, int high) {
	if (low >= high) return;
	int p = partition(arr, low, high);
	quick_sort(arr, low, p - 1);
	quick_sort(arr, p + 1, high);
}

// quick_sort的非递归写法(利用栈),思想上像层序遍历
void non_recursive_quick_sort(int arr[], int low, int high) {
	SqStack stack;
	stack_init(&stack);
	stack_push(&stack, low);
	stack_push(&stack, high);
	while (!stack_empty(stack)) {
		int high = stack_pop(&stack);
		int low = stack_pop(&stack);
		int p = partition(arr, low, high);
		if (low < p - 1) {
			stack_push(&stack, low);
			stack_push(&stack, p - 1);
		}
		if (p + 1 < high) {
			stack_push(&stack, p + 1);
			stack_push(&stack, high);
		}
	}
	stack_destroy(&stack);
}


void quick_sort_2(int arr[], int l, int r) {  //一开始自己写的合并在一起的写法
	if (l >= r) return;
	int pivot = arr[l];
	int i = l, j = r;
	while (i < j) {
		while (i < j && arr[j] >= pivot) {
			j--;
		}// i == j || arr[j] < pivot
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot) {
			i++;
		}// i == j || arr[i] > pivot
		arr[j] = arr[i];
	} // l == r
	arr[i] = pivot;
	quick_sort(arr, l, i - 1);
	quick_sort(arr, i + 1, r);
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

// 左孩子 2i+1  右孩子 2i+2  从0开始
void heapify(int arr[], int n, int k) {
	int l_idx = 2 * k + 1;
	int r_idx = 2 * k + 2;
	int largest_idx = k;

	if (l_idx < n && arr[l_idx] > arr[largest_idx]) {
		largest_idx = l_idx;
	}
	if (r_idx < n && arr[r_idx] > arr[largest_idx]) {
		largest_idx = r_idx;
	}
	if (largest_idx != k) {
		swap(&arr[k], &arr[largest_idx]);
		heapify(arr, n, largest_idx);
	}
	return;
}

void heap_sort(int arr[], int n) {
	// 从倒数第一个分支节点开始建大根堆
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// 排序
	// 不断交换首尾元素排序
	for (int j = n - 1; j > 0; j--) {
		swap(&arr[0], &arr[j]);
		heapify(arr, j, 0);  // 注意传入的n要不断减少,第一次执行时为n-1
	}
}

void merge(int arr[], int left, int mid, int right) {
	int* tmp = (int*)malloc(sizeof(arr[0]) * (right - left + 1));
	//int tmp[100];

	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		while (i <= mid && j <= right && arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		}
		while (i <= mid && j <= right && arr[j] < arr[i]) {
			tmp[k++] = arr[j++];
		}
	} // i>mid || j>right
	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	while (j <= right) {
		tmp[k++] = arr[j++];
	}

	// 复制数组
	for (int z = 0; z < right - left + 1; z++){
		arr[left + z] = tmp[z];
	}

	free(tmp);

}

void merge_sort(int arr[],int left,int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void print_arr(int arr[],int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}