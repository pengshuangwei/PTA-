#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 1000
typedef struct TreeNode* pTree;
struct TreeNode {
	int data;
	pTree Left;
	pTree Right;
};
typedef struct QTree* Q;
struct queue {
	pTree P;
	struct queue* next;
};
struct QTree {
	struct queue* rear;
	struct queue* front;
};
void ReadData(int* Pre, int* In, int num);
pTree CreateTree(pTree Root, int* Pre, int pn, int* In, int in, int num);
void PostTravsal(pTree Root, int num, Q Queue);
void Push(Q Queue, pTree P);
pTree Pop(Q Queue);
int IsEmpty(Q Queue);
int main()
{
	int* Pre, *In;
	int num, i;
	Q Queue;
	Queue = (Q)malloc(sizeof(struct QTree));
	if (!Queue) {
		printf("ERROR");
		return -1;
	}
	Queue->front = Queue->rear = NULL;
	pTree Root = NULL;
	scanf_s("%d", &num);
	Pre = (int*)malloc(sizeof(int) * num);
	In = (int*)malloc(sizeof(int) * num);
	ReadData(Pre, In, num);
	for (i = 0; i < num; i++) {
		printf("%d\t", Pre[i]);
		printf("%d\n", In[i]);
	}
	Root = CreateTree(Root, Pre, 0, In, 0, num);
	PostTravsal(Root, num, Queue);
	free(Pre);
	free(In);

	return 0;

}
void ReadData(int* Pre, int* In, int num)
{
	int pn, in;
	char str[5];
	int i, j;

	pn = in = 0;
	for (i = 0; i < num * 2; i++) {
		scanf_s("%s", str, 5);
		if (strcmp(str, "Push") == 0) {
			scanf_s("%d", &Pre[pn++]);
		}
		else if (strcmp(str, "Pop") == 0) {
			int data, n, isfound;

			n = pn;
			data = 0;
			while (n > -1) {
				isfound = 1;
				n--;
				data = Pre[n];
				for (j = 0; j < in; j++) {
					if (In[j] == data) {
						isfound = 0;
						break;
					}
				}
				if (isfound) {
					In[in++] = data;
					break;
				}
			}
		}
	}
}
pTree CreateTree(pTree Root, int* Pre, int pn, int* In, int in, int num)
{
	int L = 0, i;
	if (num == 0) {
		return NULL;
	}
	Root = (pTree)malloc(sizeof(struct TreeNode));
	if (Root == NULL) {
		printf("ERROR");
		return NULL;
	}
	if (num == 1) {
		Root->data = Pre[pn];
		Root->Left = Root->Right = NULL;
		return Root;
	}
	else {
		for (i = 0; i < num; i++) {
			if (Pre[pn] == In[in + i]) {
				L = i;
				break;
			}
		}
		Root->data = Pre[pn];
		Root->Left = CreateTree(Root->Left, Pre, pn + 1, In, in, L);
		Root->Right = CreateTree(Root->Right, Pre, pn + L + 1, In, in + L + 1, num - L - 1);
		return Root;
	}
}
void PostTravsal(pTree Root, int num, Q Queue)
{
	int flag = 0;
	pTree s = NULL;

	Push(Queue, Root);
	while (IsEmpty(Queue)) {
		s = Pop(Queue);
		if (flag == 0) flag = 1;
		else printf(" ");
		printf("%d", s->data);
		Push(Queue, s->Left);
		Push(Queue, s->Right);
		free(s);
	}
}
void Push(Q Queue, pTree P)
{
	struct queue* cur = NULL;
	if (P == NULL) {
		return;
	}
	cur = (struct queue*)malloc(sizeof(struct queue));
	if (cur == NULL) {
		printf("ERROR");
		return;
	}
	if (!IsEmpty(Queue)) {
		cur->P = P;
		cur->next = NULL;
		Queue->front = Queue->rear = cur;
	}
	else {
		cur->P = P;
		cur->next = NULL;
		Queue->rear->next = cur;
		Queue->rear = cur;
	}
}
pTree Pop(Q Queue)
{
	struct queue* Cur = NULL;
	pTree root = NULL;
	if (!IsEmpty(Queue)) {
		printf("╤сап©у");
		return NULL;
	}
	else {
		Cur = Queue->front;
		if (Queue->front == Queue->rear) {
			Queue->front = Queue->rear = NULL;
		}
		else {
			Queue->front = Queue->front->next;
		}
		root = Cur->P;
		free(Cur);
	}
	return root;
}
int IsEmpty(Q Queue)
{
	if (Queue->front == NULL && Queue->rear == NULL)
		return 0;
	else
		return -1;
}