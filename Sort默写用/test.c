#include "test.h"

// 测试 7 种比较排序的性能：分别排序 1000，2000，4000，8000，16000个元素。并验证一下各个排序算法的时间复杂度 (提示：使用 clock() 函数)。
//(注意事项：1.数据的分布应该一致; 2.不要把排序后的数组传递给下一个待测函数; 3.如果栈空间不够用, 可以在堆上申请空间)。

/*
* @brief: 传入待排数组和排序算法，给出排序花费的时间。
* @param cmp_f: 排序的算法
* @param arr[]: 待排序的数组
* @param n: 传入数组的长度
* @ret: 返回值为花费的时间(s)
*/
double test_sort_performance(void cmp_f(int*,int),int arr[],int n) {
	clock_t start_t, end_t;
	double total_t;
	start_t = clock();
	cmp_f(arr, n);
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	return total_t;
}

/*
* @brief 创建一个个数为n的动态数组，数组中的整型数字随机均匀分布
* @param arr 用于返回动态数组的指针
* @param n 动态数组的大小
*/
void create_random_array(int** arr, int n) {
	*arr = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int random_num = rand() % n;
		(*arr)[i] = random_num;
	}
}

/*
* @brief 销毁动态数组
*/
void destroy_random_array(int* arr) {
	free(arr);
}

void cpy_array(int* dest_arr, int* src_arr, int n) {
	for (int i = 0; i < n; i++) {
		dest_arr[i] = src_arr[i];
	}
}
