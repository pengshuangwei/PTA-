#include <stdio.h>
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
struct queue{
	pTree P;
	struct queue *next;
};
struct QTree {
	struct queue* rear;
	struct queue* front;
};
void ReadData(int* Pre, int* In, int num);
pTree CreateTree(pTree Root, int* Pre, int pn, int* In, int in,int num);
void PostTravsal(pTree Root,int num);
void Push(Q Queue, pTree P);
pTree Pop(Q Queue);
int IsEmpty(Q Queue);
int main()
{
	int* Pre, * In;
	int num;

	pTree Root = NULL;
	scanf_s("%d", &num);
	Pre = (int*)malloc(num * sizeof(int));
	In = (int*)malloc(num * sizeof(int));
	ReadData(Pre, In, num);
	Root = CreateTree(Root, Pre, 0, In, 0, num);
	PostTravsal(Root,num);
	free(Pre);
	free(In);
	return 0;
}

void ReadData(int* Pre, int* In,int num)
{
	int pn, in;
	char str[5];
	int j, i;


	pn = in = 0;
	j = -1;
	for (i = 0; i < num * 2; i++) {
		scanf_s("%s", str, 5);
		if (strcmp(str, "Push") == 0) {
			scanf_s("%d", &Pre[pn++]);
			j++;
		}
		else if (strcmp(str, "Pop") == 0) {
			int data, n, isfound;

			isfound = 1;
			n = pn;
			while (n) {
				data = Pre[n--];
				for (j = 0; j <= in; j++) {
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

pTree CreateTree(pTree Root, int* Pre, int pn, int* In, int in,int num)
{
	Root = (pTree)malloc(sizeof(struct TreeNode));
	if (Root == NULL) {
		printf("ÉêÇëÊ§°Ü");
		return NULL;
	}
	Root->Left = Root->Right = NULL;
	if (num == 0) {
		return NULL;
	}
	if (num == 1) {
		Root->data = Pre[pn];
		Root->Left = Root->Right = NULL;
	}
	else {
		int L=0, i;
		for (i = 0; i < num; i++) {
			if (Pre[pn] == In[in + i]) {
				L = i;
				break;
			}
		}
		Root->Left = CreateTree(Root->Left, Pre, pn + 1, In, in + L + 1, L);
		Root->Right = CreateTree(Root->Right, Pre, pn + L + 1, In, in + L + 1, num - L - 1);
	}

	return Root;
}

void PostTravsal(pTree Root, int num)
{
	int flag = 0;
	Q Queue;
	Queue = (Q)malloc(sizeof(struct QTree));
	if (!Queue) {
		printf("ERROR");
		return -1;
	}
	pTree s;
	Push(Queue, Root);
	while (!IsEmpty(Queue)) {
		s = Pop(Queue);
		if (flag == 0) {
			flag = 1;
		}
		else {
			printf(" ");
		}
		printf("%d", s->data);
		free(s);
		Push(Queue, Root->Left);
		Push(Queue, Root->Right);

	}
}

void Push(Q Queue, pTree P)
{
	struct queue *Cur=NULL;
	if (IsEmpty(Queue)) {
		Queue->front->P = Queue->rear->P = P;
		Queue->front->next = Queue->rear->next = NULL;
	}
	else {
		Cur->P = P;
		Cur->next = Queue->front->next;
		Queue->front = Cur;
	}
}

pTree Pop(Q Queue)
{
	struct queue *Cur;
	if (!IsEmpty(Queue)) {
		printf("Îª¿Õ");
		return NULL;
	}
	else {
		Cur = Queue->front;
		if (Queue->front == Queue->rear) {
			Queue->front = Queue->rear = NULL;
		}else{
			Queue->front = Queue->front->next;
		}
	}
	return Cur->P;
}

int IsEmpty(Q Queue)
{
	if (Queue->front == NULL)
		return 0;
	else
		return 1;
}
