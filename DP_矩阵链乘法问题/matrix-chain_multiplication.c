#include <stdio.h>
#include<stdlib.h>

/*
* DP_矩阵链问题（n个矩阵相乘）
* param p:矩阵链，[0]~[n]，长度为n+1；
* param m:一个二维数组，存最低代价(返回)，[1][1]~[n][n]
* param s:一个二维数组，存切割点(返回)，[1][2]~[n-1][n]
*/
void matrix_chain_order(int n,int p[],int* m[], int* s[]) {  //注意二维数组的参数传递写法
	
	//初始化代价数组(便于后续处理)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			m[i][j] = -1;
		}
	}

	//单独一个矩阵的乘法代价为0
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}

	//非平凡矩阵处理
	for (int l = 2; l <= n; l++) {//矩阵链长度
		for (int i = 1; i <= n - l + 1; i++) { //i指向长度为l的矩阵链的第一个矩阵
			for (int k = i; k <= i + l - 2; k++) { //k指向切割位置（比如k=1表明在第一个矩阵后面切割）
				int cost = m[i][k] + m[k + 1][i + l - 1] + p[i - 1] * p[k] * p[i + l - 1];
				if (cost < m[i][i + l - 1] || m[i][i+l-1]==-1) {
					m[i][i + l - 1] = cost;  //更新代价
					s[i][i + l - 1] = k;     //更新切割位置
				}
			}
		}
	}
}

//打印乘法方案
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

	//创建动态的二维数组m和k，分别记录代价和切割点
	int** m = (int**)malloc(sizeof(int*) * (n+1));
	for (int i = 0; i < n + 1; i++) {
		m[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	int** s = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		s[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	matrix_chain_order(n, p, m, s);

	//打印乘法方案
	print_optimal_parens(s, 1, n);

	printf("\nend\n");
}