void swap(int* a, int* b) { //使用时，要记得进行取地址操作
	int temp = *a;
	*a = *b;
	*b = temp;
}

//shellSort
void shell_sort(int arr[], int n) {
	int i, j, gap, temp;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			temp = arr[i];//待插入的元素
			for (j = i - gap; j >= 0 && temp < arr[j]; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}

//bubbleSort
void bubble_sort(int arr[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//heapify堆化(大根堆),首元素不为空
void heapify(int arr[], int n, int i) {
	int l_child = 2 * i + 1;
	int r_child = 2 * i + 2;
	int largest = i;

	if (l_child<n && arr[l_child] > arr[largest]) {
		largest = l_child;
	}
	if (r_child<n && arr[r_child] > arr[largest]) {
		largest = r_child;
	}

	if (largest != i) {  //说明堆顶节点需要下沉，让位给更大的值
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);  //递归heapify(largest此时仍指向原来的位置，但值已经被交换)
	}
}

//heapSort(大根堆)
void heap_sort(int arr[], int n) {
	//从倒数第一个非叶子节点开始往上heapify
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(arr, n, i);
	}

	//排序,依次将堆顶元素放到末尾
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);//注意是i,大根堆的元素数量减少
	}
}

//merge(输入数组的左右两部分要求已有序)
void merge(int arr[], int left, int mid, int right) {
	/*int* tmp = (int*)malloc(sizeof(int) * (right - left + 1));*/
	int tmp[100] = { 0 };
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {  //要有等号鸭
			tmp[k] = arr[i];
			i++;
			k++;
		}
		else {
			tmp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		tmp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= right) {
		tmp[k] = arr[j];
		j++;
		k++;
	}

	//复制到原数组
	for (int z = 0; z < right - left + 1; z++) {
		arr[left + z] = tmp[z];
	}

	//free(tmp);
}

void merge_sort_aux(int arr[], int left, int right) {
	if (left == right) return;

	int mid = (left + right) / 2;
	merge_sort_aux(arr, left, mid);
	merge_sort_aux(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

//mergeSort
void merge_sort(int arr[], int n) {
	merge_sort_aux(arr, 0, n - 1);
}

