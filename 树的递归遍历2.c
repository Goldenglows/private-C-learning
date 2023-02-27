//
//  main.c
//  tree
//
//  Created by Dong Jiang on 2022/10/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKMAXSIZE 100

struct biTreeNode{
    char data;
    struct biTreeNode * lChild;
    struct biTreeNode * rChild;
};

void createBiTree(struct biTreeNode ** t){
    printf("Input node elem: ");
    char ch = getchar();
    getchar();
    
    if(ch == '#'){
        (* t) = NULL;
    }
        
    else{
        (* t) = (struct biTreeNode *)malloc(sizeof(struct biTreeNode));
        (* t)->data = ch;
        
        createBiTree(&(* t)->lChild);
        createBiTree(&(* t)->rChild);
    }
}

void preOrderTraverse(struct biTreeNode * t){
    if(t != NULL){
        printf("%c", t->data);
        preOrderTraverse(t->lChild);
        preOrderTraverse(t->rChild);
    }
}

void inOrderTraverse(struct biTreeNode * t){
    if(t != NULL){
        inOrderTraverse(t->lChild);
        printf("%c", t->data);
        inOrderTraverse(t->rChild);
    }
}

void postOrderTraverse(struct biTreeNode *t){
    if(t != NULL){
        postOrderTraverse(t->lChild);
        postOrderTraverse(t->rChild);
        printf("%c", t->data);
    }
}

int main(){
    
    struct biTreeNode * t = NULL;
    createBiTree(&t);
    printf("A binary tree is created\n\n");

    printf("PreOrderTraverse:");
    preOrderTraverse(t);
    printf("\n\n");
    
    printf("InOrderTraverse:");
    inOrderTraverse(t);
    printf("\n\n");
    
    printf("PostOrderTraverse:");
    postOrderTraverse(t);
    printf("\n\n");
    
    return 0;
}


