#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// ���ڵ�ṹ��
typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node, * Tree;

// ջ�ṹ��
typedef struct Stack {
    Tree data[MAX_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void init(Stack* s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* s) {
    return s->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// ��ջ
void push(Stack* s, Tree x) {
    if (isFull(s)) {
        printf("The stack is full.\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

// ��ջ
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return;
    }
    s->top--;
}

// ��ȡջ��Ԫ��
Tree getTop(Stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return NULL;
    }
    return s->data[s->top];
}

// ����������ǵݹ飩
void preOrderTraversal(Tree T) {
    if (T == NULL) {
        return;
    }

    Stack s;
    init(&s);
    push(&s, T);

    while (!isEmpty(&s)) {
        Tree p = getTop(&s);
        printf("%c ", p->data);
        pop(&s);

        if (p->rchild != NULL) {
            push(&s, p->rchild);
        }

        if (p->lchild != NULL) {
            push(&s, p->lchild);
        }
    }
}

int main() {
    /* ������
         A
        / \
       B   C
      / \   \
     D   E   F
    */
    Tree A = (Tree)malloc(sizeof(Node));
    A->data = 'A';
    Tree B = (Tree)malloc(sizeof(Node));
    B->data = 'B';
    Tree C = (Tree)malloc(sizeof(Node));
    C->data = 'C';
    Tree D = (Tree)malloc(sizeof(Node));
    D->data = 'D';
    Tree E = (Tree)malloc(sizeof(Node));
    E->data = 'E';
    Tree F = (Tree)malloc(sizeof(Node));
    F->data = 'F';

    A->lchild = B;
    A->rchild = C;
    B->lchild = D;
    B->rchild = E;
    C->rchild = F;
    D->lchild = NULL;
    D->rchild = NULL;
    E->lchild = NULL;
    E->rchild = NULL;
    F->lchild = NULL;
    F->rchild = NULL;

    printf("Preorder Traversal of the Tree:\n");
    preOrderTraversal(A); // ��������ǵݹ�������Ϊ��A B D E C F

    return 0;
}
