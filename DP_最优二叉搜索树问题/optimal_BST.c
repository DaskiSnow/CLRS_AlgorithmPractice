#include<stdio.h>
#include<stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

void optimal_bts(double p[], double q[], int n, double* e[], double* r[]);
double** create_two_dim_array(int first_dim, int second_dim);

int main(void) {
	double p[] = {-1,0.15,0.1,0.05,0.1,0.2};
	double q[] = {0.05,0.1,0.05,0.05,0.05,0.1};
	int n = SIZE(p) - 1;
	double** e = create_two_dim_array(n + 2, n + 1);
	double** root = create_two_dim_array(n + 2, n + 1);
	optimal_bts(p, q, n, e, root);

	return 0;
}

// @brief: �����Ŷ����������Ĵ���(�����DP_����˷�����)
// @param: p �ؼ��ֵĸ���
// @param: q α�ؼ��ֵĸ���
// @param: n �ؼ��ֵĸ���
// @param: e һ����¼���۵�dp��ά����; e[1][2] ��ʾ����1~2�ؼ����������Ĵ���; �ر��, e[i][i-1] ��ʾ������α�ؼ���d[i-1] 
// @param: r һ����¼���Ŷ����������и��������ڵ�Ķ�ά����; r[1][2] ��ʾ����1~2�ؼ����������ĸ��ڵ�
// @ret: void 
void optimal_bts(double p[], double q[], int n, double* e[], int* root[]) {
	// w[1~n+1][0~n]  [i + 1][i] ��ʾ����α�ؼ���q[i], �����������С
	// w�洢�ؼ��ֺ�α�ؼ��ֵĸ��ʺ�; w[1][2]=p[1]+p[2]+q[0]+q[1]+q[2]
	double** w = create_two_dim_array(n + 2, n + 1);
	
	// Ԥ��ʼ��e���飬����������۵ıȽ�
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 1; j++) {
			e[i][j] = -1;
		}
	}

	// ��ʼ��e�����w����
	for (int i = 0; i <= n; i++) {
		e[i + 1][i] = q[i];
		w[i + 1][i] = q[i];
	}

	// �������
	for (int l = 1; l <= n; l++) {  // ����
		for (int i = 1; i <= n - l + 1; i++) { // ĳһ�ε���Ԫ��
			int j = i + l - 1; // ĳһ�ε�βԪ��
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int r = i; r <= j; r++) {// ������ͬ�ĸ��������
				double new_e = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (new_e < e[i][j] || e[i][j] == -1) {
					e[i][j] = new_e;
					root[i][j] = r;
				}
			}
		}
	}
}

double** create_two_dim_array(int first_dim, int second_dim) {
	double** arr = (double**)malloc(sizeof(double*) * first_dim);
	if (!arr) {
		printf("malloc failed in create_two_dim_array.\n");
		exit(1);
	}
	for (int i = 0; i < first_dim; i++) {
		arr[i] = (double*)malloc(sizeof(double) * second_dim);
		if (!arr[i]) {
			printf("malloc failed in create_two_dim_array.\n");
			exit(1);
		}
	}
	return arr;
}

