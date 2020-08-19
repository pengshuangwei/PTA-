#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReadData(int* Pre, int* In, int num);
void solve(int* Pre, int pn, int* In, int in, int num, int* Post, int pl);
void Print(int* Post, int num);
int main()
{
	int num;
	int* Pre, * In, * Post;

	scanf_s("%d", &num);
	Pre = (int*)malloc(sizeof(int) * num);
	In = (int*)malloc(sizeof(int) * num);
	Post = (int*)malloc(sizeof(int) * num);
	ReadData(Pre, In, num);
	solve(Pre, 0, In, 0, num, Post, 0);
	Print(Post, num);

	return 0;
}

void ReadData(int* Pre, int* In, int num)
{
	int pn, in;
	char str[5];
	int j, i;


	pn = in = 0;
	for (j = 0; j < num; j++) {
		In[j] = 0;
	}
	for (i = 0; i < num * 2; i++) {
		scanf_s("%s", str, 5);
		if (strcmp(str, "Push") == 0) {
			scanf_s("%d", &Pre[pn]);
			pn++;
		}
		else if (strcmp(str, "Pop") == 0) {
			int data = 0, n, isfound;

			n = pn;
			while (n > -1) {
				n--;
				data = Pre[n];
				isfound = 1;
				for (j = 0; j < in; j++) {
					if (In[j] == data) {
						isfound = 0;
						break;
					}
				}
				if (isfound) {
					In[in] = data;
					in++;
					break;
				}
			}
		}
	}
}

void solve(int* Pre, int pn, int* In, int in, int num, int* Post, int pl)
{
	int i = 0, L = 0;
	if (num == 0) {
		return;
	}
	if (num == 1) {
		Post[pl + num - 1] = Pre[pn];
		return;
	}
	Post[pl + num - 1] = Pre[pn]
		;	for (i = 0; i < num; i++) {
		if (In[in + i] == Pre[pn]) {
			L = i;
			break;
		}
	}
	solve(Pre, pn + 1, In, in, L, Post, pl);
	solve(Pre, pn + L + 1, In, in + L + 1, num - L - 1, Post, pl + L);
}

void Print(int* Post, int num)
{
	int i = 0, flag = 0;
	for (i = 0; i < num; i++) {
		if (!flag) flag = 1;
		else printf(" ");
		printf("%d", Post[i]);
	}
}
