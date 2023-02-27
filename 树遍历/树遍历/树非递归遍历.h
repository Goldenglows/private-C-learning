#include "栈.h"

BiNode* Creat(char* str, int* i, int len) { //树的创建
	struct BiNode* bt = NULL;
	char ch = str[(*i)++];
	if (ch == '#' || *i >= len) {//组成空节点
		bt = NULL;
	}
	else {
		bt = (struct BiNode*)malloc(sizeof(BiNode));
		if (bt != NULL) {
			bt->data = ch;
			bt->Lchild = Creat(str, i, len); //创造树的左右结点
			bt->rchild = Creat(str, i, len);
		}
	}
	return bt;//返回根结点
}

void visit(Datatype e) {//输出结点内容
	printf("%c ", e);
}

void PreOrder(BiNode* bt) { //树的先序遍历
	SqStack s;
	s = InitStack();
	BiNode* p = bt;
	while (p != NULL || StackEmpty(&s) != 1) { //当p为空，栈也为空时退出循环
		while (p != NULL) {
			visit(p->data);//访问根结点
			Push(&s, p); //将指针p的节点压入栈中
			p = p->Lchild; //遍历左子树
		}
		if (StackEmpty(&s) != 1) { //栈不为空
			p = Pop(&s); //根结点出栈,相当于回退
			p = p->rchild; //遍历右子树
		}
	}
	DestroyStack(&s);

	printf("\n");
}

void MidOrder(BiNode* bt) { //树的中序遍历
	SqStack s;
	s = InitStack();
	BiNode* p = bt;
	while (p != NULL || StackEmpty(&s) != 1) { //当p为空，栈也为空时退出循环
		while (p != NULL) {
			Push(&s, p); //将指针p的节点压入栈中
			p = p->Lchild; //遍历左子树
		}
		if (StackEmpty(&s) != 1) { //栈不为空
			p = Pop(&s); //根结点出栈,相当于回退
			visit(p->data);//访问根结点
			p = p->rchild; //遍历右子树
		}
	}
	DestroyStack(&s);

	printf("\n");
}

void PostOrder(BiNode* bt) { //树的后序遍历
	SqStack s;
	s = InitStack_1();
	BiNode* p = bt;
	element elem;
	while (p != NULL || StackEmpty_1(&s) != 1) { //当p为空，栈也为空时退出循环
		if (p != NULL) {//第一次入栈，访问左子树
			elem.ptr = p;
			elem.flag = 1; //标记flag为1，表示即将第一次入栈
			Push_1(&s, elem); //将指针p的结点第一次压入栈中
			p = p->Lchild;
		}
		else {
			elem = Pop_1(&s); //出栈
			p = elem.ptr; //p指向当前要处理的结点
			if (elem.flag == 1) {
				//flag==1时，说明只访问过左子树，还要访问右子树
				elem.flag = 2;
				Push_1(&s, elem); //结点第二次压入栈中
				p = p->rchild;
			}
			else {
				//flag==2时，左右子树都已经访问过了
				visit(p->data);
				p = NULL; //访问后，p赋为空，确保下次循环时继续出栈（相当于回退）
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