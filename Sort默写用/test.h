#include <time.h>
#include <stdio.h>
#include <stdlib.h>

double test_sort_performance(void cmp_f(int*, int), int arr[], int n);
void create_random_array(int* arr, int n);
void destroy_random_array(int* arr);
void cpy_array(int* dest_arr, int src_arr, int n);