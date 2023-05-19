#include "test.h"

// ���� 7 �ֱȽ���������ܣ��ֱ����� 1000��2000��4000��8000��16000��Ԫ�ء�����֤һ�¸��������㷨��ʱ�临�Ӷ� (��ʾ��ʹ�� clock() ����)��
//(ע�����1.���ݵķֲ�Ӧ��һ��; 2.��Ҫ�����������鴫�ݸ���һ�����⺯��; 3.���ջ�ռ䲻����, �����ڶ�������ռ�)��

/*
* @brief: �����������������㷨���������򻨷ѵ�ʱ�䡣
* @param cmp_f: ������㷨
* @param arr[]: �����������
* @param n: ��������ĳ���
* @ret: ����ֵΪ���ѵ�ʱ��(s)
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
* @brief ����һ������Ϊn�Ķ�̬���飬�����е���������������ȷֲ�
* @param arr ���ڷ��ض�̬�����ָ��
* @param n ��̬����Ĵ�С
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
* @brief ���ٶ�̬����
*/
void destroy_random_array(int* arr) {
	free(arr);
}

void cpy_array(int* dest_arr, int* src_arr, int n) {
	for (int i = 0; i < n; i++) {
		dest_arr[i] = src_arr[i];
	}
}
