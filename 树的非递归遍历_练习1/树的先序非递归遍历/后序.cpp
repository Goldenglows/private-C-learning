#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // ����ջ������С

// ���ṹ�嶨��
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ջ�ṹ�嶨��
typedef struct Stack {
    int top;
    TreeNode* arr[MAX_STACK_SIZE];
} Stack;

// ��ʼ��ջ
void init(Stack* s) {
    s->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int is_empty(Stack* s) {
    return s->top == -1;
}

// �ж�ջ�Ƿ�����
int is_full(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// ��ջ����
void push(Stack* s, TreeNode* node) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->arr[++(s->top)] = node;
}

// ��ջ����
TreeNode* pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// ��ȡջ��Ԫ��
TreeNode* get_top(Stack* s) {
    if (is_empty(s)) {
        return NULL;
    }
    return s->arr[s->top];
}

// ��������ǵݹ�ʵ��
void postorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack s1, s2; // ��������ջ
    init(&s1);
    init(&s2);
    push(&s1, root);
    while (!is_empty(&s1)) { // ģ��ݹ����
        TreeNode* node = pop(&s1);
        push(&s2, node);
        if (node->left != NULL) {
            push(&s1, node->left);
        }
        if (node->right != NULL) {
            push(&s1, node->right);
        }
    }
    while (!is_empty(&s2)) { // ����������
        printf("%d ", pop(&s2)->val);
    }
}

// ���Գ���
int main() {
    // ��������������
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

    // ���к������
    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
