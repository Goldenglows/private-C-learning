#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define OVERFLOW -2
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100//�洢�ռ�ĳ�ʼ������

typedef struct BiTNode { //��
	char data;
	BiTNode *lchild, *rchild; //���Һ���ָ��

} BiNode, *BiTree;


typedef struct { //ջ
	BiTNode *base;
	BiTNode *top;
	int stacksize;//ջ���õ��������
	int flag;
} SqStack;

int InitBiTree(BiTree &T) { //����ն�����
	T = NULL;
	return 1;
}


int InitStack(SqStack &S) { //����һ����ջ
	S.base = new BiTNode[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base; //��ջ����top��base��ֵ���
	S.stacksize = MAXSIZE; //
	return 1;
}

int StackEmpty(SqStack S) { //�п�
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int Push(SqStack &S, BiTNode e) { //��ջ
	if (S.top - S.base == S.stacksize) //ջ��
		return ERROR;
	*S.top = e; //Ԫ��eѹ��ջ����ջ��ָ���1
	S.top++;
	return 1;
}

int Pop(SqStack &S, BiTNode &e) { //��ջ
	//ɾ��S��ջ��Ԫ�أ�����e������ֵ
	if (S.top == S.base)
		return ERROR;

	e = *--S.top;
	return 1;
}


void CreateBiTree(BiTree &T) { //������������
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode; //���ɸ��ڵ�
		T->data = ch;
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
}

void Destroy(BiTree &T) { //���ٶ�����
	if (T) //�ǿ�{
		if (T->lchild) //������
			Destroy(T->lchild);
	if (T->rchild) //���Һ���
		Destroy(T->rchild);
	free(T);
	T = NULL;
}


//����ݹ����
void PreOrderTraverse(BiTree T) {
	if (T) {
		cout << T->data;
		printf("\t");
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

//����ݹ����
void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);
		cout << T->data;
		printf("\t");
		InOrderTraverse(T->rchild);
	}
}

//����ݹ����
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
		printf("\t");
	}
}

//����ǵݹ����
int InOrderTraverse1(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p, *q;
	p = T;
	q = new BiTNode;
	while (p || !StackEmpty(S)) {
		if (p) { //��ָ���ջ������������
			Push(S, *p);
			p = p->lchild;
		} else { //��ָ����ջ�����ʸ��ڵ㣬����������
			Pop(S, *q);
			cout << q->data << "\t";
			p = q->rchild;
		}
	}
	printf("\n");
	return 1;
}

//ǰ��ǵݹ����
int PreOrderTraverse1(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p, *q;
	p = T;
	q = new BiTNode;
	while (p || !StackEmpty(S)) {

		if (p) { //��ָ���ջ������������
			Push(S, *p);
			cout << p->data << "\t";
			p = p->lchild;
		} else { //��ָ����ջ�����ʸ��ڵ㣬����������

			Pop(S, *q);
			p = q->rchild;
		}
	}
	printf("\n");
	return 1;
}

//����ǵݹ����
int PostOrderTraversel(BiTree T) {
	SqStack S;
	InitStack(S);
	BiTNode *p;
	p = T;
	char tag[MAXSIZE] = {'0'};
	while (p || !StackEmpty(S)) {
		if (p) { //p�ǿգ�����ջ��֮��p������
			Push(S, *p);
			tag[S.flag] = '0';//��־����Ƿ����������
			p = p->lchild;
		} else { //pΪ�գ����ջ
			while (tag[S.flag] == '1') {
				Pop(S, *p);
				cout << p->data << "\t";
			}
//�ҷǿգ���p������ջ���ظ���ջ��־flag��Ϊ�棬֮��p������
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
	printf("��������������\n");
	CreateBiTree(T);

	printf("����ݹ������\n");
	PreOrderTraverse(T);
	printf("\n");

	printf("����ݹ������\n");
	InOrderTraverse(T);
	printf("\n");

	printf("����ݹ������\n");
	PostOrderTraverse(T);
	printf("\n");

	printf("����ǵݹ������\n");
	PreOrderTraverse1(T);
	printf("\n");

	printf("����ǵݹ������\n");
	InOrderTraverse1(T);
	printf("\n");

	printf("����ǵݹ������\n");
	PostOrderTraversel(T);
	printf("\n");

	getchar();
	getchar();
}