#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

//*���������ݽṹ����*
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode* left;
    struct BiTreeNode* right;
}BiTreeNode, * BiTree;

//*�������Ľ���--��������ʽ����--����*
void CreateBiTree(BiTree* T)
{
    char val;
    scanf("%c", &val);

    if (val == '#')
        *T = NULL;  //null��ʾΪ��֦
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data = val;
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}


//*�������  ������*
void PreOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    printf("%c ", T->data);
    PreOrderTravel(T->left);
    PreOrderTravel(T->right);
}

//*������� �����*
void InOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTravel(T->left);
    printf("%c ", T->data);
    InOrderTravel(T->right);
}

//*������� ���Ҹ�*
void TailOrderTravel(BiTree T)
{
    if (T == NULL)
        return;
    TailOrderTravel(T->left);
    TailOrderTravel(T->right);
    printf("%c ", T->data);
}
int main()
{
    BiTree T;
    T = (BiTree)malloc(sizeof(BiTreeNode));
    printf("�����������������ʽ�����������ֵ(�ս��Ϊ#):\n");
    CreateBiTree(&T);
    printf("����ʽ���������\n");
    PreOrderTravel(T);
    printf("\n");
    printf("����ʽ���������\n");
    InOrderTravel(T);
    printf("\n");
    printf("����ʽ���������\n");
    TailOrderTravel(T);
    printf("\n");
    return 0;
}
