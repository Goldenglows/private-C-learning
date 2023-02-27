#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Stack {
    int size;
    int top;
    TreeNode** data;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->data = (TreeNode**) malloc(size * sizeof(TreeNode*));
    return stack;
}

void push(Stack* stack, TreeNode* value) {
    if (stack->top == stack->size - 1) {
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

TreeNode* pop(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    TreeNode* value = stack->data[stack->top];
    stack->top--;
    return value;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack* stack = createStack(1000);
    TreeNode* node = root;
    while (node != NULL || !isEmpty(stack)) {
        while (node != NULL) {
            push(stack, node);
            node = node->left;
        }
        node = pop(stack);
        printf("%d ", node->val);
        node = node->right;
    }
    free(stack->data);
    free(stack);
}

int main() {
    TreeNode* node1 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node2 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node3 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node4 = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode* node5 = (TreeNode*) malloc(sizeof(TreeNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    node5->val = 5;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = NULL;
    node3->left = node5;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
    inorderTraversal(node1);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    return 0;
}
