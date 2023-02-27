#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义二叉树结构体
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 定义栈结构体
typedef struct Stack {
    int top;
    TreeNode* items[MAX_SIZE];
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isStackFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈
void push(Stack* stack, TreeNode* item) {
    if (isStackFull(stack)) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

// 出栈
TreeNode* pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    } else {
        TreeNode* item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

// 获取栈顶元素
TreeNode* peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    } else {
        return stack->items[stack->top];
    }
}

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// 构建二叉搜索树
TreeNode* buildBST(int arr[], int n) {
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// 非递归后序遍历
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);
    push(&stack1, root);

    while (!isStackEmpty(&stack1)) {
        TreeNode* node = pop(&stack1);
        push(&stack2, node);

        if (node->left) {
            push(&stack1, node->left);
        }

        if (node->right) {
            push(&stack1, node->right);
        }
    }

    while (!isStackEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}


