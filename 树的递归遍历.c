#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//��������� 
struct TreeNode{
    char data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
};

//������ 
void CreateTree(struct TreeNode * T){
    printf("���������Ľ��: ");
    char ch = getchar();
    getchar();
    if(ch == '#'){
        t = NULL;
    }
    else{
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = ch;
        
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}

//���ʽ��
void visit(struct TreeNode* T) {  

	printf("%c\n",T->data);
}

//����ݹ����
void PreOder(struct TreeNode* T) {  
	if (T != NULL) {
		visit(T);                    //���ʸ����
		PreOder(T->lchild);          //�ݹ����������
		PreOder(T->rchild);          //�ݹ����������
	}
}

//����ݹ����
void InOder(struct TreeNode* T) {  

	if (T != NULL) {
		PreOder(T->lchild);            //�ݹ����������
		visit(T);                      //���ʸ��ڵ�
		PreOder(T->rchild);            //�ݹ����������
	}
}

//����ݹ����
void PostOder(struct TreeNode* T) {
	if (T != NULL) {
		PreOder(T->lchild);            //�ݹ����������
		PreOder(T->rchild);            //�ݹ����������
		visit(T);                      //���ʸ��ڵ�
	}
}

int main(){
    
    struct TreeNode * T = NULL;
    createBiTree(&t);

	printf("����ݹ������");
	PreOder(T);
	printf("\n");

	printf("����ݹ������");
	InOder(T);
	printf("\n");

	printf("����ݹ������");
	PostOder(T);
	printf("\n");
    
    return 0;
}


