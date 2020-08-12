#include<stdio.h>
typedef struct {
    int data[10];
}Data;
void create(Data* data, int N, int L);
void dealdata(Data *data,int N,int L, int* Root);
void IsOnetree(Data* data, int N, int L,int *Root);
int main() {
    int N, L;
    while (1) {
        scanf_s("%d", &N);
        if (N == 0) break;
        else {
            scanf_s("%d", &L);
            Data data[4];
            int Root[4];
            create(data, N, L);
            dealdata(data, N, L,Root);
            IsOnetree(data, N, L,Root);
        }
    }
    return 0;
}
void create(Data* data, int N, int L)
{
    int i = 0, j = 0;
    for (i = 0; i < L + 1; i++) {
        for (j = 0; j < N; j++) {
            scanf_s("%d", &data[i].data[j]);
        }
    }
}
void dealdata(Data* data, int N, int L,int *Root)
{
    int i, j, k;
    int root;
    int num[10];
    for (i = 0; i < L + 1; i++) {
        root = data[i].data[0];
        k = 0;
        for (j = 0; j < N; j++) {
            if (data[i].data[j] < root) {
                num[k++] = data[i].data[j];
            }
        }
        num[k++] = root;
        Root[i] = root;
        for (j = 0; j < N; j++) {
            if (data[i].data[j] > root) {
                data[i].data[j] = num[k++];
            }
        }
        for (j = 0; j < N; j++) {
            data[i].data[j] = num[j];
        }
    }
}
void IsOnetree(Data* data, int N, int L,int *Root)
{
    int i, j, isfound;
    isfound = 1;
    for (i = 1; i < L + 1; i++) {
        if (Root[0] != Root[i]) {
            printf("No\n");
            break;
        }
        for (j = 0; j < N; j++) {
            if (data[0].data[j] != data[i].data[j]) {
                printf("No\n");
                isfound = 0;
                break;
            }
        }
        if (isfound) printf("Yes\n");
    }
}
/*
算法的缺陷在于怎么对类似4231和4213类似数据的处理
*/
