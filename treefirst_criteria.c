#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 树节点结构体定义
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 栈结构体定义
typedef struct Stack {
    TreeNode *data[MAX_SIZE];
    int top;
} Stack;

// 栈初始化
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 元素入栈
void push(Stack *s, TreeNode *node) {
    if (isFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->data[++s->top] = node;
}

// 元素出栈
TreeNode *pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return NULL;
    }
    return s->data[s->top--];
}

// 非递归先序遍历
void preOrderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    Stack s;
    initStack(&s);
    push(&s, root);

    while (!isEmpty(&s)) {
        TreeNode *node = pop(&s);
        printf("%d ", node->data);

        if (node->right != NULL) {
            push(&s, node->right);
        }
        if (node->left != NULL) {
            push(&s, node->left);
        }
    }
}

// 创建树节点
TreeNode *createTreeNode(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 创建二叉搜索树
TreeNode *createBST(TreeNode *root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }

    if (data < root->data) {
        root->left = createBST(root->left, data);
    } else if (data > root->data) {
        root->right = createBST(root->right, data);
    }

    return root;
}

int main() {
    TreeNode *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        root = createBST(root, arr[i]);
    }

    preOrderTraversal(root);
    printf("\n");

    return 0;
}

