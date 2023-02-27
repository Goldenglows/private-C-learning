#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//定义树结点 
struct TreeNode{
    char data;
    struct TreeNode * lchild;
    struct TreeNode * rchild;
};

//创建树 
void CreateTree(struct TreeNode * T){
    printf("请输入树的结点: ");
    char ch = getchar();
    getchar();
    if(ch == '#'){
        t = NULL;
    }
    else{
        T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        T->data = ch;
        
        CreateTree(t->lchild);
        CreateTree(t->rchild);
    }
}

//访问结点
void visit(struct TreeNode* T) {  

	printf("%c\n",T->data);
}

//先序递归遍历
void PreOder(struct TreeNode* T) {  
	if (T != NULL) {
		visit(T);                    //访问根结点
		PreOder(T->lchild);          //递归遍历左子树
		PreOder(T->rchild);          //递归遍历右子树
	}
}

//中序递归遍历
void InOder(struct TreeNode* T) {  

	if (T != NULL) {
		PreOder(T->lchild);            //递归遍历左子树
		visit(T);                      //访问根节点
		PreOder(T->rchild);            //递归遍历右子树
	}
}

//后序递归遍历
void PostOder(struct TreeNode* T) {
	if (T != NULL) {
		PreOder(T->lchild);            //递归遍历左子树
		PreOder(T->rchild);            //递归遍历右子树
		visit(T);                      //访问根节点
	}
}

int main(){
    
    struct TreeNode * T = NULL;
    createBiTree(&t);

	printf("先序递归遍历：");
	PreOder(T);
	printf("\n");

	printf("中序递归遍历：");
	InOder(T);
	printf("\n");

	printf("后序递归遍历：");
	PostOder(T);
	printf("\n");
    
    return 0;
}


