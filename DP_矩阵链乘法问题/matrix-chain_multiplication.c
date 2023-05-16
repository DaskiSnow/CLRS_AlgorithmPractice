#include <stdio.h>
#include<stdlib.h>

/*
* DP_���������⣨n��������ˣ�
* param p:��������[0]~[n]������Ϊn+1��
* param m:һ����ά���飬����ʹ���(����)��[1][1]~[n][n]
* param s:һ����ά���飬���и��(����)��[1][2]~[n-1][n]
*/
void matrix_chain_order(int n,int p[],int* m[], int* s[]) {  //ע���ά����Ĳ�������д��
	
	//��ʼ����������(���ں�������)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			m[i][j] = -1;
		}
	}

	//����һ������ĳ˷�����Ϊ0
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}

	//��ƽ��������
	for (int l = 2; l <= n; l++) {//����������
		for (int i = 1; i <= n - l + 1; i++) { //iָ�򳤶�Ϊl�ľ������ĵ�һ������
			for (int k = i; k <= i + l - 2; k++) { //kָ���и�λ�ã�����k=1�����ڵ�һ����������и
				int cost = m[i][k] + m[k + 1][i + l - 1] + p[i - 1] * p[k] * p[i + l - 1];
				if (cost < m[i][i + l - 1] || m[i][i+l-1]==-1) {
					m[i][i + l - 1] = cost;  //���´���
					s[i][i + l - 1] = k;     //�����и�λ��
				}
			}
		}
	}
}

//��ӡ�˷�����
void print_optimal_parens(int* s[],int i,int j) {
	if (i == j) {
		printf("A%d", i);
	}
	else {
		printf("(");
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(void) {
	int p[] = { 5,10,3,12,5,50,6 };
	int n = sizeof(p) / sizeof(p[0]) - 1;

	//������̬�Ķ�ά����m��k���ֱ��¼���ۺ��и��
	int** m = (int**)malloc(sizeof(int*) * (n+1));
	for (int i = 0; i < n + 1; i++) {
		m[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	int** s = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		s[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	matrix_chain_order(n, p, m, s);

	//��ӡ�˷�����
	print_optimal_parens(s, 1, n);

	printf("\nend\n");
}