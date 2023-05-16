#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*
* �Ե�����
* param c: һ����ά���顣m[i][j]��¼��x���е�ǰi���ַ���y���е�ǰj���ַ�������������еĳ��ȡ�
* peram b: һ����ά���顣b[i][j]��¼��ȷ��m[i][j]ʱ��������ѡ��ѡ��·����
*/
void lcs_length_calc(char x[],int n,char y[],int m,int* c[], int* b[]) {
	//��c������г�ʼ��
	for (int j = 0; j <= m; j++) {
		c[0][j] = 0;
	}
	for (int i = 0; i <= n; i++) {
		c[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
}

int lcs_length(char x[], int n, char y[], int m,int*** c,int*** b) {
	*c = (int**)malloc(sizeof(int*) * (n + 1));
	if (*c == NULL) {
		printf("malloc failed in lcs_length.\n");
		exit(1);
	}
	for (int i = 0; i < n + 1; i++) {
		(*c)[i] = (int*)malloc(sizeof(int) * (m + 1));
		if ((*c)[i] == NULL) {
			printf("malloc failed in lcs_length.\n");
			exit(1);
		}
	}
	*b = (int**)malloc(sizeof(int*) * (n + 1));
	if (*b == NULL) {
		printf("malloc failed in lcs_length.\n");
		exit(1);
	}
	for (int i = 0; i < n + 1; i++) {
		(*b)[i] = (int*)malloc(sizeof(int) * (m + 1));
		if ((*b)[i] == NULL) {
			printf("malloc failed in lcs_length.\n");
			exit(1);
		}
	}


	lcs_length_calc(x, n, y, m, *c, *b);
	return (*c)[n][m];
}


/*
* ����b�ع�lcs
*/
void print_lcs_1(int* b[],char x[],int i,int j) {
	if (i == 0 || j == 0) return;
	if (b[i][j]==0) {
		print_lcs_1(b, x, i - 1, j - 1);
		printf("%c", x[i]);
	}
	else if (b[i][j]>0) {  //
		print_lcs_1(b, x, i - 1, j);
	}
	else {
		print_lcs_1(b, x, i, j - 1);
	}
}

/*
* ��ʹ��b������c�ع�lcs
*/
void print_lcs_2(int* c[], char x[], char y[],int i, int j) {
	if (i == 0 || j == 0) return;
	if (x[i] == y[j]) {
		print_lcs_2(c, x, y, i - 1, j - 1);
		printf("%c", x[i]);
	}
	else if (c[i - 1][j] >= c[i][j - 1]) {
		print_lcs_2(c, x, y, i - 1, j);
	}
	else {
		print_lcs_2(c, x, y, i, j-1);
	}
}

/*
* ������¼�ĴӶ����µĵݹ鷨
*/
int lcs_length_memo_aux(char x[], int i, char y[], int j, int* c[]) {
	if (c[i][j] >= 0) return c[i][j];
	if (x[i] == y[j]) {
		c[i][j] = lcs_length_memo_aux(x, i - 1, y, j - 1, c)+1;
		return c[i][j];
	}
	else {
		c[i][j] = max(lcs_length_memo_aux(x, i - 1, y, j, c), lcs_length_memo_aux(x, i, y, j - 1, c));
		return c[i][j];
	}
}


int lcs_length_memo(char x[], int n, char y[], int m) {
	int** c = (int**)malloc(sizeof(int*)*(n+1));
	if (c == NULL) {
		printf("malloc failed in lcs_length_memo.\n");
		exit(1);
	}
	for (int i = 0; i < n + 1; i++) {
		c[i] = (int*)malloc(sizeof(int) * (m + 1));
		if (c[i] == NULL) {
			printf("malloc failed in lcs_length_memo.\n");
			exit(1);
		}
		//��ʼ��Ϊ-1
		for (int j = 0; j < m + 1; j++) {
			if (i == 0 || j == 0) c[i][j] = 0;
			else {
				c[i][j] = -1;
			}
		}
	}
	int lcs_len=lcs_length_memo_aux(x, n, y, m, c);

	return lcs_len;
}


int main(void) {
	//char x[8] = " ABCBDAB";
	//char y[7] = " BDCABA";
	char x[] = {'*','1','0','0','1','0','1','0','1'};
	char y[] = {'*','0','1','0','1','1','0','1','1','0'};
	int** c;
	int** b;
	int length=lcs_length_memo(x,sizeof(x)-1, y, sizeof(y)-1);
	int length2 = lcs_length(x, sizeof(x) - 1, y, sizeof(y) - 1, &c, &b);
	print_lcs_1(b, x, sizeof(x) - 1, sizeof(y) - 1);
	printf("\n");
	//print_lcs_2(c,x,y, sizeof(x) - 1, sizeof(y) - 1);
	//printf("\n");
	printf("lcs����:%d", length2);
}