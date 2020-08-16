#include<stdio.h>
#include<stdlib.h>
typedef struct ACLTree* Atree;
struct ACLTree {
	int data;
	Atree left;
	Atree right;
	int height;
};
Atree Insert(Atree At, int x);
Atree SingleLeftRotation(Atree At);
Atree SingleRightRotation(Atree At);
Atree DoubleLeftRotation(Atree At);
Atree DoubleRightRotation(Atree At);
int Max(int a, int b);
int GetHeight(Atree At);

int main()
{
	int num, i, x;
	Atree At;
	At = NULL;
	scanf_s("%d", &num);
	for(i = 0; i < num; i++) {
		scanf_s("%d", &x);
		At = Insert(At, x);
	}
	if(At)
		printf("%d\n", At->data);
	return 0;

}

Atree Insert(Atree At, int x)
{
	if (!At) {
		At = (Atree)malloc(sizeof(struct ACLTree));
		if (At == NULL) {
			printf("ÉêÇëÊ§°Ü");
			return -1;
		}
		At->data = x;
		At->left = At->right = NULL;
		At->height = 0;
	}
	else if (x > At->data) {
		At->right = Insert(At->right, x);
		if (GetHeight(At->right) - GetHeight(At->left) == 2) {
			if (x > At->right->data) {
				At = SingleRightRotation(At);
			}
			else {
				At = DoubleRightRotation(At);
			}
		}
	}
	else if (x < At->data) {
		At->left = Insert(At->left,x);
		if (GetHeight(At->right) - GetHeight(At->left) == -2)
		if (x < At->left->data) {
			At = SingleLeftRotation(At);
		}
		else {
			At = DoubleLeftRotation(At);
		}
	}
	At->height = Max(GetHeight(At->left), GetHeight(At->right)) + 1;

		return At;
}

Atree SingleLeftRotation(Atree At)
{
	Atree AT = At->left;
	At->left = AT->right;
	AT->right = At;
	At->height= Max(GetHeight(At->left), GetHeight(At->right)) + 1;
	AT->height = Max(GetHeight(AT->left), GetHeight(AT->right)) + 1;
	return AT;
}

Atree SingleRightRotation(Atree At)
{
	Atree AT = At->right;
	At->right = AT->left;
	AT->left = At;
	At->height = Max(GetHeight(At->left), GetHeight(At->right)) + 1;
	AT->height = Max(GetHeight(AT->left), GetHeight(AT->right)) + 1;
	return AT;
}

Atree DoubleLeftRotation(Atree At)
{
	At->left = SingleRightRotation(At->right);
	At = SingleLeftRotation(At);
	return At;
}

Atree DoubleRightRotation(Atree At)
{
	At->right = SingleLeftRotation(At->right);
	At = SingleRightRotation(At);
	return At;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

int GetHeight(Atree At)
{
	if (!At)return -1;
	else return At->height;
}
