#include <stdio.h>
#include <stdlib.h>

// 树节点的结构体定义
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 栈节点的结构体定义
typedef struct StackNode {
    TreeNode* node;
    struct StackNode* next;
} StackNode;

// 栈的结构体定义
typedef struct Stack {
    StackNode* top;
} Stack;

// 创建新的树节点
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 将节点入栈
void push(Stack* s, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = s->top;
    s->top = newNode;
}

// 将栈顶节点出栈
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

// 判断栈是否为空
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// 中序遍历非递归函数
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack s;
    s.top = NULL;
    TreeNode* current = root;
    while (current != NULL || !isEmpty(&s)) {
        // 将左子树上的所有节点入栈
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        // 栈顶节点出栈，访问该节点
        current = pop(&s);
        printf("%d ", current->data);
        // 处理右子树
        current = current->right;
    }
}

int main() {
    // 创建一棵树
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // 中序遍历该树
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
