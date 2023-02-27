#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define OVERFLOW -2
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100//存储空间的初始分配量

typedef struct BiTNode { //树
	char data;
	BiTNode *lchild, *rchild; //左右孩子指针

} BiNode, *BiTree;


typedef struct { //栈
	BiTNode *base;
	BiTNode *top;
	int stacksize;//栈可用的最大容量
	int flag;
} SqStack;

int InitBiTree(BiTree &T) { //构造空二叉树
	T = NULL;
	return 1;
}


int InitStack(SqStack &S) { //构造一个空栈
	S.base = new BiTNode[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base; //空栈条件top和base的值相等
	S.stacksize = MAXSIZE; //
	return 1;
}

int StackEmpty(SqStack S) { //判空
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int Push(SqStack &S, BiTNode e) { //入栈
	if (S.top - S.base == S.stacksize) //栈满
		return ERROR;
	*S.top = e; //元素e压入栈顶，栈顶指针加1
	S.top++;
	return 1;
}

int Pop(SqStack &S, BiTNode &e) { //出栈
	//删除S的栈顶元素，并用e返回其值
	if (S.top == S.base)
		return ERROR;

	e = *--S.top;
	return 1;
}


void CreateBiTree(BiTree &T) { //输入树的内容
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode; //生成根节点
		T->data = ch;
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
}

void Destroy(BiTree &T) { //销毁二叉树
	if (T) //非空{
		if (T->lchild) //有左孩子
			Destroy(T->lchild);
	if (T->rchild) //有右孩子
		Destroy(T->rchild);
	free(T);
	T = NULL;
}


//先序递归遍历
void PreOrderTraverse(BiTree T) {
	if (T) {
		cout << T->data;
		printf("\t");
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//中序递归遍历
void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		printf("\t");
		InOrderTraverse(T->rchild);
	}
}

//后序递归遍历
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
		printf("\t");
	}
}

//中序非递归遍历
int InOrderTraverse1(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p, *q;
	p = T;
	q = new BiTNode;
	while (p || !StackEmpty(S)) {
		if (p) { //根指针进栈，遍历左子树
			Push(S, *p);
			p = p->lchild;
		} else { //根指针退栈，访问根节点，遍历右子树
			Pop(S, *q);
			cout << q->data << "\t";
			p = q->rchild;
		}
	}
	printf("\n");
	return 1;
}

//前序非递归遍历
int PreOrderTraverse1(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p, *q;
	p = T;
	q = new BiTNode;
	while (p || !StackEmpty(S)) {

		if (p) { //根指针进栈，遍历左子树
			Push(S, *p);
			cout << p->data << "\t";
			p = p->lchild;
		} else { //根指针退栈，访问根节点，遍历右子树

			Pop(S, *q);
			p = q->rchild;
		}
	}
	printf("\n");
	return 1;
}

//后序非递归遍历
int PostOrderTraversel(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p;
	p = T;
	char tag[MAXSIZE] = {'0'};
	while (p || !StackEmpty(S)) {
		if (p) { //p非空，则入栈，之后p向左走
			Push(S, *p);
			tag[S.flag] = '0';//标志结点是否遍历右子树
			p = p->lchild;
		} else { //p为空，则出栈
			while (tag[S.flag] == '1') {
				Pop(S, *p);
				cout << p->data << "\t";
			}
//右非空，则p重新入栈，重复入栈标志flag置为真，之后p向右走
			if (S.flag == -1)
				break;

			Pop(S, *p);
			Push(S, *p);
			p = p->rchild;
			tag[S.flag] = '1';
		}
	}
}



int main() {

	BiTree T;

	InitBiTree(T);
	printf("请先序输入树：\n");
	CreateBiTree(T);

	printf("先序递归遍历：\n");
	PreOrderTraverse(T);
	printf("\n");

	printf("中序递归遍历：\n");
	InOrderTraverse(T);
	printf("\n");

	printf("后序递归遍历：\n");
	PostOrderTraverse(T);
	printf("\n");

	printf("先序非递归遍历：\n");
	PreOrderTraverse1(T);
	printf("\n");

	printf("中序非递归遍历：\n");
	InOrderTraverse1(T);
	printf("\n");

	printf("后序非递归遍历：\n");
	PostOrderTraversel(T);
	printf("\n");

	getchar();
	getchar();
}