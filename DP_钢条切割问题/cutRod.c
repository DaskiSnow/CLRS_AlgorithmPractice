#include<stdio.h>
#include<stdlib.h>

//�Զ����µ����صݹ鷨
int cut_rod(int p[], int n) {
	if (n == 0) return 0;
	int max_p = -1;  //Ҫ����cut_rod�����ڲ�����Ҫ���ں�����ߡ�
	for (int i = 1; i <= n; i++) {
		max_p = max(p[i] + cut_rod(p, n - i), max_p);
	}
	return max_p;
}

//�Զ����´�����¼�ĵݹ鷨
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
	for (int i = 0; i <= n; i++) {//��ʼ��
		r[i] = -1;
	}
	return memoized_cut_rod_aux(p, n, r);
}

//�Ե����ϵĴ�����¼�汾���Ե����ϵĶ�̬�滮����
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
* ���Ե����ϵĶ�̬�滮�������ϣ������ܱ������и���ļ�¼����
* @param p:�۸��
* @param n:��Ҫ���и�ĸ�������
* @param r:���ڱ����������ֵ������
* @param s:���ڱ����и��������
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
	int p[] = { 0,1,5,8,9,10,17,17,20,24,30 };//��ͬ�ߴ������
	int* r = NULL;  //�����������
	int* s = NULL;  //�����и��
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

	//��ӡ�и��
	for (int i = 1; i < n; i++) {
		printf("r[%d]=%d, �и�� %d=", i, r[i], i);
		int remaining_len = i;
		while (remaining_len > 0) {
			printf("%d ", s[remaining_len]);
			remaining_len -= s[remaining_len];
		}
		printf("\n");
	}
}