#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define Maxsize 30

typedef struct BiTreeNode {
	ElemType data;
	struct BiTreeNode *LChild, * RChild;
} *BiTree;

typedef struct SqStack {
	BiTree data[Maxsize];
	int top;
} *Stack;

Stack InitStack() { //����ջ
	Stack S;
	S = (Stack)malloc(sizeof(SqStack));
	S->top = -1;
	return S;
}

int StackEmpty(SqStack S) { //�п�
	if (S.top == -1)
		return 1;
	else
		return 0;
}

void Push (Stack S, BiTree p) { //��ջ
	S->top++;
	S->data[S->top] = p;
}

void Pop(Stack S, BiTree *p) { //��ջ
	*p = S->data[S->top];
	S->top--;
}

BiTree CreateBiTree() {
	char ch;
	BiTree T;
	scanf_s("%c", &ch, 1);
	if (ch == '#')
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = ch;
		T->LChild = CreateBiTree();
		T->RChild = CreateBiTree();
	}
	return T;
}//������������

//����ݹ����
void PreOrder(BiTree T) {
	if (T) {
		printf("%c", p->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//����ݹ����
void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		printf("%c", p->data);
		InOrder(T->rchild);
	}
}

//����ݹ����
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", p->data);
	}
}

//����ǵݹ����
int NonrecursivePre(BiTree T) {
	SqStack *S;
	S = InitStack();
	BiTreeNode *p;
	p = T;
	while (p || !StackEmpty(*S)) {
		if (p) {
			printf("%c", p->data);
			Push(S, p);
			p = p->LChild;
		} else {
			Pop(S, &p);
			p = p->RChild;
		}
	}
}

//����ǵݹ����
int NonrecursiveIn(BiTree T) {
	SqStack *S;
	S = InitStack();
	BiTreeNode *p;
	p = T;
	while (p || !StackEmpty(*S)) {
		if (p) {
			Push(S, p);
			p = p->LChild;
		} else {
			Pop(S, &p);
			printf("%c", p->data);
			p = p->RChild;
		}
	}
}

//����ǵݹ����
int NonrecursivePost(BiTree T) {
	SqStack *S;
	S = InitStack();
	BiTreeNode *p;
	p = T;
	char tag[Maxsize] = {'0'};
	while (p || !StackEmpty(*S)) {
		if (p) {
			Push(S, p);
			tag[S->top] = '0';//��־����Ƿ����������
			p = p->LChild;
		} else {
			while (tag[S->top] == '1') {
				Pop(S, &p);
				printf("%c", p->data);
			}
			if (S->top == -1)
				break;
			Pop(S, &p);
			Push(S, p);
			p = p->RChild;
			tag[S->top] = '1';
		}
	}

	int main() {

		BiTree T;

		InitBiTree(T);
		printf("��������������\n");
		CreateBiTree(T);

		printf("����ݹ������\n");
		PreOrder(T);
		printf("\n");

		printf("����ݹ������\n");
		InOrder(T);
		printf("\n");

		printf("����ݹ������\n");
		PostOrder(T);
		printf("\n");

		printf("����ǵݹ������\n");
		NonrecursivePre(T);
		printf("\n");

		printf("����ǵݹ������\n");
		NonrecursiveIn(T);
		printf("\n");

		printf("����ǵݹ������\n");
		NonrecursivePost(T);
		printf("\n");

		return 1;

		getchar();
		getchar();
	}