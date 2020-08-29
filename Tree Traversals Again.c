/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Maxsize 30
typedef struct TreeNode* BinTree;
struct TreeNode {
    int x;
    BinTree Left;
    BinTree Right;
    BinTree Front;
};
BinTree CreateTree();
void PostOrderTraversal(BinTree BT);

int main()
{
    BinTree Root;
    Root = CreateTree();
    PostOrderTraversal(Root);


}

BinTree CreateTree()
{
    int i, isfound = 1;
    BinTree Tmp, previous, Root, current;
    Tmp = previous = Root = current = NULL;
    int num, count = 0;
    char ch[6];
    scanf_s("%d", &num);
    for (i = 0; i < num*2; i++) {
        scanf_s("%s",ch,6);
        if (strcmp(ch, "Push") == 0) {
            Tmp = (BinTree)malloc(sizeof(struct TreeNode));
            if (!Tmp) {
                printf("ÉêÇëÊ§°Ü");
            }
            if (!Root && isfound == 1) {
                Root = Tmp; 
                Tmp->Front = NULL;
            }
            else if (previous != NULL) {
                if (isfound == 1) {
                    previous->Left = Tmp;
                    Tmp->Front = previous;
                }
                else {
                    previous->Right = Tmp;
                    Tmp->Front = previous;
                }
            }
            scanf_s("%d", &Tmp->x);
            Tmp->Left = Tmp->Right = NULL;
            previous = Tmp;
        }
        else if (strcmp(ch, "Pop") == 0) {
            if (count) {
                current = previous->Front;
                previous = current;
                isfound = 0;
            }
            else {
                count = 1;
            }
        }
    }
    return Root;
}
void PostOrderTraversal(BinTree BT)
{
    static count = 1;
    if (BT) {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        if (count == 1) {
            count = 0;
        }
        else {
            printf(" ");
            printf("------->");
        }
        printf("%d", BT->x);
    }
}
/*
最大的错误在于想当然的直接将数据加在了左结点。

*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TreeNode* pTree;
//定义结构体指针 
struct TreeNode {
	int data;
	pTree Left;
	pTree Right;
};
void ReadData(int* Pre, int* In, int num);
//处理数据，将其按照前序和中序的顺序分别储存在两个数组中 
pTree CreateTree(pTree Root, int* Pre, int pn, int* In, int in, int num);
//根据得到的数据建立原来的树 
void PostTravsal(pTree Root);
//后序输出函数 

int main()
{
	int* Pre, * In;
	int num, i;

	pTree Root = NULL;
	scanf("%d", &num);
	Pre = (int*)malloc(num * sizeof(int));
	In = (int*)malloc(num * sizeof(int));
	ReadData(Pre, In, num);
	for (i = 0; i < num; i++) {
		printf("%d\t", Pre[i]);
		printf("%d\n", In[i]);
	}
	Root = CreateTree(Root, Pre, 0, In, 0, num);
	PostTravsal(Root);
	free(Pre);
	free(In);
	return 0;
}

void ReadData(int* Pre, int* In, int num)
//  Pre 前序数组 In 中序数组 num  数据总数 
{
	int pn, in;
	char str[5];
	int j, i;


	pn = in = 0;
	for (j = 0; j < num; j++) {
		In[j] = 0;
	}
	for (i = 0; i < num * 2; i++) {
		scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			scanf("%d", &Pre[pn]);
			pn++;
		}
		else if (strcmp(str, "Pop") == 0) {
			int data = 0, n, isfound;

			n = pn;
			while (n > -1) {
				//将前序数据储存为中序 
				isfound = 1;
				n--;
				data = Pre[n];
				for (j = 0; j < in; j++) {
					//排除已储存的中序数据 
					if (In[j] == data) {
						isfound = 0;
						break;
					}
				}
				if (isfound) {
					//将未储存的数据储存下来 
					In[in] = data;
					in++;
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
		//验空 
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
		//递归储存左子树和右子树的数据 
		Root->data = Pre[pn];
		Root->Left = CreateTree(Root->Left, Pre, pn + 1, In, in, L);
		Root->Right = CreateTree(Root->Right, Pre, pn + L + 1, In, in + L + 1, num - L - 1);
		return Root;
	}
}

void PostTravsal(pTree Root)
{
	static int flag = 0;
	if (Root) {
		PostTravsal(Root->Left);
		PostTravsal(Root->Right);
		if (flag == 0) flag = 1;
		else printf(" ");
		printf("%d", Root->data);
	}
}