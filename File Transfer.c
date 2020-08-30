#include<stdio.h>
#include<stdlib.h>
typedef struct SetNode* Set;
struct SetNode {
	int parent;
};//定义集合的数据结构
void Check(Set set);//检查两个个体之间是否连接起来
int Find(Set set, int x);//找到x结点的根节点
void Union(Set set);//将两个根节点合并起来
void Checkset(Set set,int num);//检查整个集合共有多少连通集

int main()
{
	int num,i;
	char letter;

	scanf_s("%d", &num);
	Set set;
	set = (Set)malloc(sizeof(struct SetNode) * (num + 1));
	if (!set) {
		//验空
		printf("ERROR");
		return -1;
	}
	for (i = 0; i <= num; i++) {
		//将每个结点的父节点信息初始化
		set[i].parent = -1;
	}
	
	do {//循环进行检查和连接操作，直到结束指令
		getchar();
		scanf_s("%c", &letter, 1);
		switch (letter)
		{
		case 'C':Check(set);
			break;
		case 'I':Union(set);
			break;
		default:
			Checkset(set,num);
			break;
		}
	} while (letter != 'S');

	return 0;
}

void Check(Set set)
{
	int c1, c2;
	int Root1, Root2;
	scanf_s("%d %d", &c1, &c2);
	Root1 = Find(set,c1);
	Root2 = Find(set,c2);
	if (Root1 == Root2) printf("yes\n");
	else printf("no\n");
}

int Find(Set set, int x)
{
	for (; set[x].parent > 0; x = set[x].parent);
	//循环找到根结点
	return x;
	//返回根结点的下标
}

void Union(Set set)
{
	int Root1, Root2;
	int c1, c2;
	scanf_s("%d %d", &c1, &c2);
	Root1 = Find(set, c1);
	Root2 = Find(set, c2);
	if (Root1 <= Root2) {
		set[Root1].parent += set[Root2].parent;
		set[Root2].parent = Root1;
	}
	else {
		set[Root2].parent += set[Root1].parent;
		set[Root1].parent = Root2;
	}
}

void Checkset(Set set, int num)
{
	int i = 1;
	int count = 0;
	for (i; i <= num; i++) {
		if (set[i].parent < 0)count++;
	}
	if (count == 1) {
		printf("The network is connected.");
	}
	else {
		printf("There are %d components.\n", count);
	}
}