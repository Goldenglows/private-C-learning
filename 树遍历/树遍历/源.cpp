#include"���ǵݹ����.h"

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
	printf("�������������");
	PreOrder(bt);
	printf("�������������");
	MidOrder(bt);
	printf("���ĺ��������");
	PostOrder(bt);


}








//struct TreeNode {//���ڵ�
//    int data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
////���ķǵݹ��������
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
////���ķǵݹ��������
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
////���ķǵݹ�������
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
//    // ����һ��������
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
//    printf("���ķǵݹ��������:");
//    preOrderTraversal(root);
//    printf("���ķǵݹ��������:");
//    inOrderTraversal(root);
//    printf("���ķǵݹ�������:");
//    postOrderTraversal(root);
//}
//
//
//
//
//
////���Ĳ������
