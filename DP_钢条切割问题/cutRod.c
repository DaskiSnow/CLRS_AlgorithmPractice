#include<stdio.h>
#include<stdlib.h>

//自顶向下的朴素递归法
int cut_rod(int p[], int n) {
	if (n == 0) return 0;
	int max_p = -1;  //要放在cut_rod函数内部，不要放在函数外边。
	for (int i = 1; i <= n; i++) {
		max_p = max(p[i] + cut_rod(p, n - i), max_p);
	}
	return max_p;
}

//自顶向下带备忘录的递归法
int memoized_cut_rod_aux(int p[], int n, int r[]) {
	if (r[n] >= 0) return r[n];
	if (n == 0) {
		return 0;
	}
	else {
		int max_p = -1;
		for (int i = 1; i <= n; i++) {
			max_p = max(max_p, p[i] + memoized_cut_rod_aux(p, n - i, r));
		}
		r[n] = max_p;
		return max_p;
	}
}

int memoized_cut_rod(int p[], int n) {
	int* r = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++) {//初始化
		r[i] = -1;
	}
	return memoized_cut_rod_aux(p, n, r);
}

//自底向上的带备忘录版本（自底向上的动态规划法）
int bottom_up_cut_rod(int p[], int n) {
	int* r = (int*)malloc(sizeof(int) * (n + 1));

	r[0] = 0;
	for (int i = 1; i <= n; i++) {
		int max_p = -1;
		for (int j = 1; j <= i; j++) {
			max_p = max(max_p, p[j] + r[i - j]);
			r[i] = max_p;
		}
	}

	return r[n];
}
/*
* 在自底向上的动态规划法基础上，增加能保存其切割方案的记录数组
* @param p:价格表
* @param n:需要被切割的钢铁长度
* @param r:用于保存最佳收益值的数组
* @param s:用于保存切割方案的数组
*/
void extended_bottom_up_cut_rod(int p[], int n, int* r, int* s) {
	r[0] = 0;
	for (int i = 1; i <= n; i++) {
		int max_p = -1;
		for (int j = 1; j <= i; j++) {
			if (max_p < p[j] + r[i - j]) {
				max_p = max(max_p, p[j] + r[i - j]);
				r[i] = max_p;
				s[i] = j;
			}
		}
	}
}

int main(void) {
	int p[] = { 0,1,5,8,9,10,17,17,20,24,30 };//不同尺寸的收益
	int* r = NULL;  //保存最佳收益
	int* s = NULL;  //保存切割方案
	int n = sizeof(p) / sizeof(p[0]);
	r = (int*)malloc(sizeof(int) * (n));
	s = (int*)malloc(sizeof(int) * (n));
	extended_bottom_up_cut_rod(p, 10, r, s);

	/*for (int i = 0; i < n; i++) {
		printf("r[%d]: %d\n", i, r[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("s[%d]: %d\n", i, s[i]);
	}*/

	//打印切割方案
	for (int i = 1; i < n; i++) {
		printf("r[%d]=%d, 切割方案 %d=", i, r[i], i);
		int remaining_len = i;
		while (remaining_len > 0) {
			printf("%d ", s[remaining_len]);
			remaining_len -= s[remaining_len];
		}
		printf("\n");
	}
}