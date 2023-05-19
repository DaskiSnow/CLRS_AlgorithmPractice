#include "sort_dictation.h"
#include "test.h"
#include<stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

int main2(void) {
	// 测试1000个元素时各排序算法的性能
	printf("************************测试1000个元素时各排序算法的性能START**********************************\n");
	int* src_arr_1000;
	double total_t;
	create_random_array(&src_arr_1000, 1000);

	int arr_1000[1000];
	//未解之谜：下面一句代码，动态分配的数组作为函数参数传入后，为什么会访问冲突？
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_1000, 1000);
	printf("选择排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_1000, 1000);
	printf("堆排序花费时间约: %e秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_1000, 1000);
	printf("冒泡排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_1000, 1000);
	printf("快速排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_1000, 1000);
	printf("直接插入排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_1000, 1000);
	printf("希尔排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_1000, 1000);
	printf("归并排序花费时间约: %e 秒\n", total_t);

	destroy_random_array(src_arr_1000);
	printf("************************测试1000个元素时各排序算法的性能END**********************************\n");

	// 测试2000个元素时各排序算法的性能
	printf("************************测试2000个元素时各排序算法的性能START**********************************\n");
	int* src_arr_2000;
	create_random_array(&src_arr_2000, 2000);

	int arr_2000[2000];
	//未解之谜：下面一句代码，动态分配的数组作为函数参数传入后，为什么会访问冲突？
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_2000, 2000);
	printf("选择排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_2000, 2000);
	printf("堆排序花费时间约: %e秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_2000, 2000);
	printf("冒泡排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_2000, 2000);
	printf("快速排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_2000, 2000);
	printf("直接插入排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_2000, 2000);
	printf("希尔排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_2000, 2000);
	printf("归并排序花费时间约: %e 秒\n", total_t);

	destroy_random_array(src_arr_2000);
	printf("************************测试2000个元素时各排序算法的性能END**********************************\n");


	// 测试4000个元素时各排序算法的性能
	printf("************************测试4000个元素时各排序算法的性能START**********************************\n");
	int* src_arr_4000;
	create_random_array(&src_arr_4000, 4000);

	int arr_4000[4000];
	//未解之谜：下面一句代码，动态分配的数组作为函数参数传入后，为什么会访问冲突？
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_4000, 4000);
	printf("选择排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_4000, 4000);
	printf("堆排序花费时间约: %e秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_4000, 4000);
	printf("冒泡排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_4000, 4000);
	printf("快速排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_4000, 4000);
	printf("直接插入排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_4000, 4000);
	printf("希尔排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_4000, 4000);
	printf("归并排序花费时间约: %e 秒\n", total_t);

	destroy_random_array(src_arr_4000);
	printf("************************测试4000个元素时各排序算法的性能END**********************************\n");


	// 测试8000个元素时各排序算法的性能
	printf("************************测试8000个元素时各排序算法的性能START**********************************\n");
	int* src_arr_8000;
	create_random_array(&src_arr_8000, 8000);

	int arr_8000[8000];
	//未解之谜：下面一句代码，动态分配的数组作为函数参数传入后，为什么会访问冲突？
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_8000, 8000);
	printf("选择排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_8000, 8000);
	printf("堆排序花费时间约: %e秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_8000, 8000);
	printf("冒泡排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_8000, 8000);
	printf("快速排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_8000, 8000);
	printf("直接插入排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_8000, 8000);
	printf("希尔排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_8000, 8000);
	printf("归并排序花费时间约: %e 秒\n", total_t);

	destroy_random_array(src_arr_8000);
	printf("************************测试8000个元素时各排序算法的性能END**********************************\n");

	// 测试16000个元素时各排序算法的性能
	printf("************************测试16000个元素时各排序算法的性能START**********************************\n");
	int* src_arr_16000;
	create_random_array(&src_arr_16000, 16000);

	int arr_16000[16000];
	//未解之谜：下面一句代码，动态分配的数组作为函数参数传入后，为什么会访问冲突？
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_16000, 16000);
	printf("选择排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_16000, 16000);
	printf("堆排序花费时间约: %e秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_16000, 16000);
	printf("冒泡排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_16000, 16000);
	printf("快速排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_16000, 16000);
	printf("直接插入排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_16000, 16000);
	printf("希尔排序花费时间约: %e 秒\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_16000, 16000);
	printf("归并排序花费时间约: %e 秒\n", total_t);

	destroy_random_array(src_arr_16000);
	printf("************************测试16000个元素时各排序算法的性能END**********************************\n");
}