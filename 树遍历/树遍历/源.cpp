#include"树非递归遍历.h"

int main() {
	BiNode* bt;
	int i = 0;
	int len;
	char str[100] ={"abc##d##ef##g##"};
	/*
			a
		   /  \
	      b    e
		 / \  / \
		c  d  f  g
	       
	*/
	len = strlen(str);
	bt = Creat(str, &i, len);
	printf("树的先序遍历：");
	PreOrder(bt);
	printf("树的中序遍历：");
	MidOrder(bt);
	printf("树的后序遍历：");
	PostOrder(bt);


}








//struct TreeNode {//树节点
//    int data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
////树的非递归先序遍历
//void preOrderTraversal(struct TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = -1;
//    stack[++top] = root;
//    while (top >= 0) {
//        struct TreeNode* node = stack[top--];
//        printf("%d ", node->data);
//        if (node->right != NULL) {
//            stack[++top] = node->right;
//        }
//        if (node->left != NULL) {
//            stack[++top] = node->left;
//        }
//    }
//    free(stack);
//}
//
////树的非递归中序遍历
//void inOrderTraversal(struct TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = -1;
//    struct TreeNode* node = root;
//    while (top >= 0 || node != NULL) {
//        while (node != NULL) {
//            stack[++top] = node;
//            node = node->left;
//        }
//        node = stack[top--];
//        printf("%d ", node->data);
//        node = node->right;
//    }
//    free(stack);
//}
//
////树的非递归后序遍历
//void postOrderTraversal(struct TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
//    int top = -1;
//    struct TreeNode* node = root;
//    struct TreeNode* last = NULL;
//    while (top >= 0 || node != NULL) {
//        while (node != NULL) {
//            stack[++top] = node;
//            node = node->left;
//        }
//        struct TreeNode* temp = stack[top];
//        if (temp->right == NULL || temp->right == last) {
//            printf("%d ", temp->data);
//            top--;
//            last = temp;
//        }
//        else {
//            node = temp->right;
//        }
//    }
//    free(stack);
//}
//
//int main() {
//    // 构造一个二叉树
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    root->data = 1;
//    struct TreeNode* node2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node2->data = 2;
//    struct TreeNode* node3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node3->data = 3;
//    struct TreeNode* node4 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node4->data = 4;
//    struct TreeNode* node5 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    node5->data = 5;
//
//    printf("树的非递归先序遍历:");
//    preOrderTraversal(root);
//    printf("树的非递归中序遍历:");
//    inOrderTraversal(root);
//    printf("树的非递归后序遍历:");
//    postOrderTraversal(root);
//}
//
//
//
//
//
////树的层序遍历
