#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// 树节点结构体
typedef struct Node {
    char data;
    struct Node* lchild;
    struct Node* rchild;
} Node, * Tree;

// 栈结构体
typedef struct Stack {
    Tree data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void init(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// 入栈
void push(Stack* s, Tree x) {
    if (isFull(s)) {
        printf("The stack is full.\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

// 出栈
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return;
    }
    s->top--;
}

// 获取栈顶元素
Tree getTop(Stack* s) {
    if (isEmpty(s)) {
        printf("The stack is empty.\n");
        return NULL;
    }
    return s->data[s->top];
}

// 先序遍历（非递归）
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
    /* 构建树
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
    preOrderTraversal(A); // 先序遍历非递归输出结果为：A B D E C F

    return 0;
}
