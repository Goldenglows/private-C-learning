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

Stack InitStack() { //创建栈
	Stack S;
	S = (Stack)malloc(sizeof(SqStack));
	S->top = -1;
	return S;
}

int StackEmpty(SqStack S) { //判空
	if (S.top == -1)
		return 1;
	else
		return 0;
}

void Push (Stack S, BiTree p) { //入栈
	S->top++;
	S->data[S->top] = p;
}

void Pop(Stack S, BiTree *p) { //出栈
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
}//输入树的内容

//先序递归遍历
void PreOrder(BiTree T) {
	if (T) {
		printf("%c", p->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序递归遍历
void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		printf("%c", p->data);
		InOrder(T->rchild);
	}
}

//后序递归遍历
void PostOrder(BiTree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", p->data);
	}
}

//先序非递归遍历
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

//中序非递归遍历
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

//后序非递归遍历
int NonrecursivePost(BiTree T) {
	SqStack *S;
	S = InitStack();
	BiTreeNode *p;
	p = T;
	char tag[Maxsize] = {'0'};
	while (p || !StackEmpty(*S)) {
		if (p) {
			Push(S, p);
			tag[S->top] = '0';//标志结点是否遍历右子树
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
		printf("请先序输入树：\n");
		CreateBiTree(T);

		printf("先序递归遍历：\n");
		PreOrder(T);
		printf("\n");

		printf("中序递归遍历：\n");
		InOrder(T);
		printf("\n");

		printf("后序递归遍历：\n");
		PostOrder(T);
		printf("\n");

		printf("先序非递归遍历：\n");
		NonrecursivePre(T);
		printf("\n");

		printf("中序非递归遍历：\n");
		NonrecursiveIn(T);
		printf("\n");

		printf("后序非递归遍历：\n");
		NonrecursivePost(T);
		printf("\n");

		return 1;

		getchar();
		getchar();
	}