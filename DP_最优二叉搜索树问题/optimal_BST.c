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

// @brief: 求最优二叉搜索树的代价(可类比DP_矩阵乘法问题)
// @param: p 关键字的概率
// @param: q 伪关键字的概率
// @param: n 关键字的个数
// @param: e 一个记录代价的dp二维数组; e[1][2] 表示包含1~2关键字最优树的代价; 特别地, e[i][i-1] 表示空树即伪关键字d[i-1] 
// @param: r 一个记录最优二叉搜索树中各子树根节点的二维数组; r[1][2] 表示包含1~2关键字最优树的根节点
// @ret: void 
void optimal_bts(double p[], double q[], int n, double* e[], int* root[]) {
	// w[1~n+1][0~n]  [i + 1][i] 表示的是伪关键字q[i], 规律是左大右小
	// w存储关键字和伪关键字的概率和; w[1][2]=p[1]+p[2]+q[0]+q[1]+q[2]
	double** w = create_two_dim_array(n + 2, n + 1);
	
	// 预初始化e数组，方便后续代价的比较
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 1; j++) {
			e[i][j] = -1;
		}
	}

	// 初始化e数组和w数组
	for (int i = 0; i <= n; i++) {
		e[i + 1][i] = q[i];
		w[i + 1][i] = q[i];
	}

	// 计算代价
	for (int l = 1; l <= n; l++) {  // 长度
		for (int i = 1; i <= n - l + 1; i++) { // 某一段的首元素
			int j = i + l - 1; // 某一段的尾元素
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int r = i; r <= j; r++) {// 遍历不同的根结点的情况
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

