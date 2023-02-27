#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACKSIZE 100
#define STACKINCREMENT 10
typedef char Datatype;

typedef struct BiNode {
	Datatype data;//��������
	struct BiNode* Lchild;//ָ�����ӽ��
	struct BiNode* rchild;//ָ���Һ��ӽ��
} BiNode;

typedef BiNode* Elemtype;
typedef struct element {
	BiNode* ptr;
	int flag;
} element;

typedef element Elemtype_1;
typedef struct {
	Elemtype* data;//����ǰ����������
	Elemtype_1* data_1;//���ں������
	int top;//ջ��ָ�룬������int���ͱ�ʾָ����±�
	int len;
} SqStack;
Elemtype Pop(SqStack* s);

SqStack InitStack() {//��ջ���캯��
	SqStack s;
	s.data = (Elemtype*)malloc(STACKSIZE * sizeof(Elemtype));
	s.top = -1; //��ʾջ��
	s.len = STACKSIZE;
	if (s.data != NULL)
	{
	}
	else
		printf("Init error!\n");
	return s;
}

void DestroyStack(SqStack* s) {//����ջ����
	free(s->data);
}

int StackEmpty(SqStack* s) {//�ж��Ƿ�Ϊ��ջ,�Ƿ���1���� ����0
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void Push(SqStack* s, Elemtype e) {//���Ԫ����ջ
	if (s->top >= s->len) {
		s->data = (Elemtype*)malloc((STACKSIZE + STACKINCREMENT) * sizeof(Elemtype));
		s->len += STACKINCREMENT;
		if (s->data != NULL) {}
		else
			printf("Push error!\n");
	}
	else {
		s->top++;
		s->data[s->top] = e;
	}
}

Elemtype Pop(SqStack* s) {
	if (StackEmpty(s) != 1 && s->top >= 0) {
		Elemtype e = s->data[s->top];
		s->top--;
		return e;
	}
	printf("Pop error!\n");
}

SqStack InitStack_1() {//��ջ���캯��
	SqStack s;
	s.data_1 = (Elemtype_1*)malloc(STACKSIZE * sizeof(Elemtype_1));
	s.top = -1; //��ʾջ��
	s.len = STACKSIZE;
	if (s.data != NULL)
	{
	}
	else
		printf("Init error!\n");
	return s;
}

void DestroyStack_1(SqStack* s) {//����ջ����
	free(s->data_1);
}

//�����������������ջ����

int StackEmpty_1(SqStack* s) {//�ж��Ƿ�Ϊ��ջ,�Ƿ���1���� ����0
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void Push_1(SqStack* s, Elemtype_1 e) {//���Ԫ����ջ
	if (s->top >= s->len) {
		s->data_1 = (Elemtype_1*)malloc((STACKSIZE + STACKINCREMENT) * sizeof(Elemtype_1));
		s->len += STACKINCREMENT;
		if (s->data_1 != NULL) {}
		else
			printf("Push error!\n");
	}
	else {
		s->top++;
		s->data_1[s->top] = e;
	}
}

Elemtype_1 Pop_1(SqStack* s) {
	if (StackEmpty(s) != 1 && s->top >= 0) {
		Elemtype_1 e = s->data_1[s->top];
		s->top--;
		return e;
	}
	printf("Pop error!\n");
}
