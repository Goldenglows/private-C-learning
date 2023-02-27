#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACKSIZE 100
#define STACKINCREMENT 10
typedef char Datatype;

typedef struct BiNode {
	Datatype data;//数据内容
	struct BiNode* Lchild;//指向左孩子结点
	struct BiNode* rchild;//指向右孩子结点
} BiNode;

typedef BiNode* Elemtype;
typedef struct element {
	BiNode* ptr;
	int flag;
} element;

typedef element Elemtype_1;
typedef struct {
	Elemtype* data;//用于前序和中序遍历
	Elemtype_1* data_1;//用于后序遍历
	int top;//栈顶指针，这里用int类型表示指针的下标
	int len;
} SqStack;
Elemtype Pop(SqStack* s);

SqStack InitStack() {//空栈构造函数
	SqStack s;
	s.data = (Elemtype*)malloc(STACKSIZE * sizeof(Elemtype));
	s.top = -1; //表示栈空
	s.len = STACKSIZE;
	if (s.data != NULL)
	{
	}
	else
		printf("Init error!\n");
	return s;
}

void DestroyStack(SqStack* s) {//销毁栈函数
	free(s->data);
}

int StackEmpty(SqStack* s) {//判断是否为空栈,是返回1，否 返回0
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void Push(SqStack* s, Elemtype e) {//添加元素入栈
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

SqStack InitStack_1() {//空栈构造函数
	SqStack s;
	s.data_1 = (Elemtype_1*)malloc(STACKSIZE * sizeof(Elemtype_1));
	s.top = -1; //表示栈空
	s.len = STACKSIZE;
	if (s.data != NULL)
	{
	}
	else
		printf("Init error!\n");
	return s;
}

void DestroyStack_1(SqStack* s) {//销毁栈函数
	free(s->data_1);
}

//以下用作后序遍历的栈内容

int StackEmpty_1(SqStack* s) {//判断是否为空栈,是返回1，否 返回0
	if (s->top == -1)
		return 1;
	else
		return 0;
}

void Push_1(SqStack* s, Elemtype_1 e) {//添加元素入栈
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
