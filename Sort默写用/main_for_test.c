#include "sort_dictation.h"
#include "test.h"
#include<stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

int main2(void) {
	// ����1000��Ԫ��ʱ�������㷨������
	printf("************************����1000��Ԫ��ʱ�������㷨������START**********************************\n");
	int* src_arr_1000;
	double total_t;
	create_random_array(&src_arr_1000, 1000);

	int arr_1000[1000];
	//δ��֮�գ�����һ����룬��̬�����������Ϊ�������������Ϊʲô����ʳ�ͻ��
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_1000, 1000);
	printf("ѡ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_1000, 1000);
	printf("�����򻨷�ʱ��Լ: %e��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_1000, 1000);
	printf("ð�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_1000, 1000);
	printf("�������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_1000, 1000);
	printf("ֱ�Ӳ������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_1000, 1000);
	printf("ϣ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 1000; i++) {
		arr_1000[i] = src_arr_1000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_1000, 1000);
	printf("�鲢���򻨷�ʱ��Լ: %e ��\n", total_t);

	destroy_random_array(src_arr_1000);
	printf("************************����1000��Ԫ��ʱ�������㷨������END**********************************\n");

	// ����2000��Ԫ��ʱ�������㷨������
	printf("************************����2000��Ԫ��ʱ�������㷨������START**********************************\n");
	int* src_arr_2000;
	create_random_array(&src_arr_2000, 2000);

	int arr_2000[2000];
	//δ��֮�գ�����һ����룬��̬�����������Ϊ�������������Ϊʲô����ʳ�ͻ��
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_2000, 2000);
	printf("ѡ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_2000, 2000);
	printf("�����򻨷�ʱ��Լ: %e��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_2000, 2000);
	printf("ð�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_2000, 2000);
	printf("�������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_2000, 2000);
	printf("ֱ�Ӳ������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_2000, 2000);
	printf("ϣ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 2000; i++) {
		arr_2000[i] = src_arr_2000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_2000, 2000);
	printf("�鲢���򻨷�ʱ��Լ: %e ��\n", total_t);

	destroy_random_array(src_arr_2000);
	printf("************************����2000��Ԫ��ʱ�������㷨������END**********************************\n");


	// ����4000��Ԫ��ʱ�������㷨������
	printf("************************����4000��Ԫ��ʱ�������㷨������START**********************************\n");
	int* src_arr_4000;
	create_random_array(&src_arr_4000, 4000);

	int arr_4000[4000];
	//δ��֮�գ�����һ����룬��̬�����������Ϊ�������������Ϊʲô����ʳ�ͻ��
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_4000, 4000);
	printf("ѡ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_4000, 4000);
	printf("�����򻨷�ʱ��Լ: %e��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_4000, 4000);
	printf("ð�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_4000, 4000);
	printf("�������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_4000, 4000);
	printf("ֱ�Ӳ������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_4000, 4000);
	printf("ϣ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 4000; i++) {
		arr_4000[i] = src_arr_4000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_4000, 4000);
	printf("�鲢���򻨷�ʱ��Լ: %e ��\n", total_t);

	destroy_random_array(src_arr_4000);
	printf("************************����4000��Ԫ��ʱ�������㷨������END**********************************\n");


	// ����8000��Ԫ��ʱ�������㷨������
	printf("************************����8000��Ԫ��ʱ�������㷨������START**********************************\n");
	int* src_arr_8000;
	create_random_array(&src_arr_8000, 8000);

	int arr_8000[8000];
	//δ��֮�գ�����һ����룬��̬�����������Ϊ�������������Ϊʲô����ʳ�ͻ��
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_8000, 8000);
	printf("ѡ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_8000, 8000);
	printf("�����򻨷�ʱ��Լ: %e��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_8000, 8000);
	printf("ð�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_8000, 8000);
	printf("�������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_8000, 8000);
	printf("ֱ�Ӳ������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_8000, 8000);
	printf("ϣ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 8000; i++) {
		arr_8000[i] = src_arr_8000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_8000, 8000);
	printf("�鲢���򻨷�ʱ��Լ: %e ��\n", total_t);

	destroy_random_array(src_arr_8000);
	printf("************************����8000��Ԫ��ʱ�������㷨������END**********************************\n");

	// ����16000��Ԫ��ʱ�������㷨������
	printf("************************����16000��Ԫ��ʱ�������㷨������START**********************************\n");
	int* src_arr_16000;
	create_random_array(&src_arr_16000, 16000);

	int arr_16000[16000];
	//δ��֮�գ�����һ����룬��̬�����������Ϊ�������������Ϊʲô����ʳ�ͻ��
	//cpy_array(arr_1000, src_arr_1000, 1000);  
	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(selection_sort, arr_16000, 16000);
	printf("ѡ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(heap_sort, arr_16000, 16000);
	printf("�����򻨷�ʱ��Լ: %e��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(bubble_sort, arr_16000, 16000);
	printf("ð�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(quick_sort, arr_16000, 16000);
	printf("�������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(direct_insertion_sort, arr_16000, 16000);
	printf("ֱ�Ӳ������򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(shell_sort, arr_16000, 16000);
	printf("ϣ�����򻨷�ʱ��Լ: %e ��\n", total_t);

	for (int i = 0; i < 16000; i++) {
		arr_16000[i] = src_arr_16000[i];
	}
	total_t = test_sort_performance(merge_sort, arr_16000, 16000);
	printf("�鲢���򻨷�ʱ��Լ: %e ��\n", total_t);

	destroy_random_array(src_arr_16000);
	printf("************************����16000��Ԫ��ʱ�������㷨������END**********************************\n");
}