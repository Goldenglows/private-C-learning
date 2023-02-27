#include "ջ.h"

BiNode* Creat(char* str, int* i, int len) { //���Ĵ���
	struct BiNode* bt = NULL;
	char ch = str[(*i)++];
	if (ch == '#' || *i >= len) {//��ɿսڵ�
		bt = NULL;
	}
	else {
		bt = (struct BiNode*)malloc(sizeof(BiNode));
		if (bt != NULL) {
			bt->data = ch;
			bt->Lchild = Creat(str, i, len); //�����������ҽ��
			bt->rchild = Creat(str, i, len);
		}
	}
	return bt;//���ظ����
}

void visit(Datatype e) {//����������
	printf("%c ", e);
}

void PreOrder(BiNode* bt) { //�����������
	SqStack s;
	s = InitStack();
	BiNode* p = bt;
	while (p != NULL || StackEmpty(&s) != 1) { //��pΪ�գ�ջҲΪ��ʱ�˳�ѭ��
		while (p != NULL) {
			visit(p->data);//���ʸ����
			Push(&s, p); //��ָ��p�Ľڵ�ѹ��ջ��
			p = p->Lchild; //����������
		}
		if (StackEmpty(&s) != 1) { //ջ��Ϊ��
			p = Pop(&s); //������ջ,�൱�ڻ���
			p = p->rchild; //����������
		}
	}
	DestroyStack(&s);

	printf("\n");
}

void MidOrder(BiNode* bt) { //�����������
	SqStack s;
	s = InitStack();
	BiNode* p = bt;
	while (p != NULL || StackEmpty(&s) != 1) { //��pΪ�գ�ջҲΪ��ʱ�˳�ѭ��
		while (p != NULL) {
			Push(&s, p); //��ָ��p�Ľڵ�ѹ��ջ��
			p = p->Lchild; //����������
		}
		if (StackEmpty(&s) != 1) { //ջ��Ϊ��
			p = Pop(&s); //������ջ,�൱�ڻ���
			visit(p->data);//���ʸ����
			p = p->rchild; //����������
		}
	}
	DestroyStack(&s);

	printf("\n");
}

void PostOrder(BiNode* bt) { //���ĺ������
	SqStack s;
	s = InitStack_1();
	BiNode* p = bt;
	element elem;
	while (p != NULL || StackEmpty_1(&s) != 1) { //��pΪ�գ�ջҲΪ��ʱ�˳�ѭ��
		if (p != NULL) {//��һ����ջ������������
			elem.ptr = p;
			elem.flag = 1; //���flagΪ1����ʾ������һ����ջ
			Push_1(&s, elem); //��ָ��p�Ľ���һ��ѹ��ջ��
			p = p->Lchild;
		}
		else {
			elem = Pop_1(&s); //��ջ
			p = elem.ptr; //pָ��ǰҪ����Ľ��
			if (elem.flag == 1) {
				//flag==1ʱ��˵��ֻ���ʹ�����������Ҫ����������
				elem.flag = 2;
				Push_1(&s, elem); //���ڶ���ѹ��ջ��
				p = p->rchild;
			}
			else {
				//flag==2ʱ�������������Ѿ����ʹ���
				visit(p->data);
				p = NULL; //���ʺ�p��Ϊ�գ�ȷ���´�ѭ��ʱ������ջ���൱�ڻ��ˣ�
			}
		}
	}
	DestroyStack_1(&s);

	printf("\n");
}

//void PREOrder(BiNode* bt) {
//	SqStack s;
//	s = InitStack();
//	BiNode* p = bt;
//
//
//
//}
//void INOrder(BiNode* bt) {
//	SqStack s;
//	s = InitStack();
//	BiNode* p = bt;
//
//
//
//}
//void POSTOrder(BiNode* bt) {
//	SqStack s;
//	s = InitStack();
//	BiNode* p = bt;
//
//
//}