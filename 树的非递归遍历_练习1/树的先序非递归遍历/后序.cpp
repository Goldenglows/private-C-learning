#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // 定义栈的最大大小

// 树结构体定义
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 栈结构体定义
typedef struct Stack {
    int top;
    TreeNode* arr[MAX_STACK_SIZE];
} Stack;

// 初始化栈
void init(Stack* s) {
    s->top = -1;
}

// 判断栈是否为空
int is_empty(Stack* s) {
    return s->top == -1;
}

// 判断栈是否已满
int is_full(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// 入栈操作
void push(Stack* s, TreeNode* node) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->arr[++(s->top)] = node;
}

// 出栈操作
TreeNode* pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// 获取栈顶元素
TreeNode* get_top(Stack* s) {
    if (is_empty(s)) {
        return NULL;
    }
    return s->arr[s->top];
}

// 后序遍历非递归实现
void postorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack s1, s2; // 定义两个栈
    init(&s1);
    init(&s2);
    push(&s1, root);
    while (!is_empty(&s1)) { // 模拟递归过程
        TreeNode* node = pop(&s1);
        push(&s2, node);
        if (node->left != NULL) {
            push(&s1, node->left);
        }
        if (node->right != NULL) {
            push(&s1, node->right);
        }
    }
    while (!is_empty(&s2)) { // 输出遍历结果
        printf("%d ", pop(&s2)->val);
    }
}

// 测试程序
int main() {
    // 构建测试用例树
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->val = 3;
    root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->left->val = 4;
    root->left->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->left->right->val = 5;
    root->right->left = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->left->val = 6;
    root->right->right = (TreeNode*)malloc(sizeof(TreeNode));
    root->right->right->val = 7;

    // 进行后序遍历
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
