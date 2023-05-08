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

int main(void) {
	int n = 6;
	int p[] = { 30,35,15,5,10,20,25 };
	
	//������̬�Ķ�ά����m��k
	int** m = (int**)malloc(sizeof(int*) * (n+1));
	for (int i = 0; i < n + 1; i++) {
		m[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	int** k = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		k[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	matrix_chain_order(n, p, m, k);

	printf("good\n");
}