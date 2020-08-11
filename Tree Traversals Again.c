#include<stdio.h>
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
