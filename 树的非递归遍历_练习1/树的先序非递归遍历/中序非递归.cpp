#include <stdio.h>
#include <stdlib.h>

// ���ڵ�Ľṹ�嶨��
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ջ�ڵ�Ľṹ�嶨��
typedef struct StackNode {
    TreeNode* node;
    struct StackNode* next;
} StackNode;

// ջ�Ľṹ�嶨��
typedef struct Stack {
    StackNode* top;
} Stack;

// �����µ����ڵ�
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���ڵ���ջ
void push(Stack* s, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = s->top;
    s->top = newNode;
}

// ��ջ���ڵ��ջ
TreeNode* pop(Stack* s) {
    if (s->top == NULL) {
        return NULL;
    }
    TreeNode* node = s->top->node;
    StackNode* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return node;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// ��������ǵݹ麯��
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack s;
    s.top = NULL;
    TreeNode* current = root;
    while (current != NULL || !isEmpty(&s)) {
        // ���������ϵ����нڵ���ջ
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        // ջ���ڵ��ջ�����ʸýڵ�
        current = pop(&s);
        printf("%d ", current->data);
        // ����������
        current = current->right;
    }
}

int main() {
    // ����һ����
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // �����������
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
