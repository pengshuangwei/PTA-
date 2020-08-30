#include<stdio.h>
#include<stdlib.h>
typedef struct SetNode* Set;
struct SetNode {
	int parent;
};//���弯�ϵ����ݽṹ
void Check(Set set);//�����������֮���Ƿ���������
int Find(Set set, int x);//�ҵ�x���ĸ��ڵ�
void Union(Set set);//���������ڵ�ϲ�����
void Checkset(Set set,int num);//����������Ϲ��ж�����ͨ��

int main()
{
	int num,i;
	char letter;

	scanf_s("%d", &num);
	Set set;
	set = (Set)malloc(sizeof(struct SetNode) * (num + 1));
	if (!set) {
		//���
		printf("ERROR");
		return -1;
	}
	for (i = 0; i <= num; i++) {
		//��ÿ�����ĸ��ڵ���Ϣ��ʼ��
		set[i].parent = -1;
	}
	
	do {//ѭ�����м������Ӳ�����ֱ������ָ��
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
	//ѭ���ҵ������
	return x;
	//���ظ������±�
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