#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct treeNode{
    char data;
    struct treeNode * lChild;
    struct treeNode * rChild;
};

struct sqQueue{
    int front;
    int rear;
    struct treeNode ** base;
};

struct sqStack{
    int top;
    struct treeNode ** base;
};

struct sqQueue * initSqQueue();
int enSqQueue(struct sqQueue * queuePointer, struct treeNode * treeNodePointer);
struct treeNode * deSqQueue(struct sqQueue * queuePointer);

struct sqStack * initSqStack();
int push(struct sqStack * stackPointer, struct treeNode * treeNodePointer);
struct treeNode * pop(struct sqStack * stackPointer);

void initTree(struct treeNode * root, struct sqQueue * queuePointer);
int levelOrderTraverse(struct treeNode * root, struct sqQueue * queuePointer);
int preOrderTraverse(struct treeNode * root, struct sqStack * stackPointer);
int inOrderTraverse(struct treeNode * root, struct sqStack * stackPointer);

int main(){
    struct sqQueue * queuePointer = initSqQueue();
    struct sqStack * stackPointer = initSqStack();

    struct treeNode * root = (struct treeNode *)malloc(sizeof(struct treeNode));

    initTree(root, queuePointer);
    levelOrderTraverse(root, queuePointer);
    preOrderTraverse(root, stackPointer);
    inOrderTraverse(root, stackPointer);

    free(queuePointer->base);
    free(queuePointer);
}


struct sqQueue * initSqQueue(){
    struct sqQueue * p = (struct sqQueue *)malloc(sizeof(struct sqQueue));
    p->front = 0;
    p->rear = 0;
    p->base = (struct treeNode **)malloc(MAXSIZE * sizeof(struct treeNode *));
    return p;
}

int enSqQueue(struct sqQueue * queuePointer, struct treeNode * treeNodePointer){
    if((queuePointer->rear + 1) % MAXSIZE == queuePointer->front){
        printf("循环队列满，无法入队!\n");
        return -1;
    }

    queuePointer->base[queuePointer->rear] = treeNodePointer;
    queuePointer->rear = (queuePointer->rear + 1) % MAXSIZE;
}

struct treeNode * deSqQueue(struct sqQueue * queuePointer){
    if(queuePointer->front == queuePointer->rear){
        printf("循环队列空，无法出队!\n");
        return NULL;
    }

    struct treeNode * temp = queuePointer->base[queuePointer->front];
    queuePointer->front = (queuePointer->front + 1) % MAXSIZE;
    return temp;
}

struct sqStack * initSqStack(){
    struct sqStack * p = (struct sqStack *)malloc(sizeof(struct sqStack));
    p->top = 0;
    p->base = (struct treeNode **)malloc(MAXSIZE * sizeof(struct treeNode *));

    return p;
}

int push(struct sqStack * stackPointer, struct treeNode * treeNodePointer){
    if(stackPointer->top == MAXSIZE - 1){
        printf("栈满，无法压栈!\n");
        return 0;
    }

    stackPointer->base[stackPointer->top++] = treeNodePointer;
    return 1;
}

struct treeNode * pop(struct sqStack * stackPointer){
    if(stackPointer->top == 0){
        printf("栈空，无法出栈!\n");
        return NULL;
    }

    return stackPointer->base[--stackPointer->top];
}

void initTree(struct treeNode * root, struct sqQueue * queuePointer){
    printf("请输入根的值:");
    scanf("%c", &root->data);
    getchar();

    enSqQueue(queuePointer, root);
    while(queuePointer->front != queuePointer->rear){
        struct treeNode * temp = deSqQueue(queuePointer);
        
        printf("请输入%c节点左子树的值:", temp->data);
        char c;
        scanf("%c", &c);
        getchar();
        if(c == '#')
            temp->lChild = NULL;
        else{
            temp->lChild = (struct treeNode *)malloc(sizeof(struct treeNode));
            temp->lChild->data = c;
            enSqQueue(queuePointer, temp->lChild);
        } 

        printf("请输入%c节点右子树的值:", temp->data);
        scanf("%c", &c);
        getchar(); 
        if(c == '#')
            temp->rChild = NULL;
        else{
            temp->rChild = (struct treeNode *)malloc(sizeof(struct treeNode));
            temp->rChild->data = c;
            enSqQueue(queuePointer, temp->rChild);
        }           
    }
}

int levelOrderTraverse(struct treeNode * root, struct sqQueue * queuePointer){
    if(root == NULL){
        printf("空树\n");
        return 0;
    }

    printf("\n层次遍历结果:");
    struct treeNode * temp = root;
    enSqQueue(queuePointer, temp);
    while(queuePointer->front != queuePointer->rear){
        temp = deSqQueue(queuePointer);
        printf("%c ", temp->data);

        if(temp->lChild != NULL)
            enSqQueue(queuePointer, temp->lChild);

        if(temp->rChild != NULL)
            enSqQueue(queuePointer, temp->rChild);
    }
    printf("\n");

    return 1;
}

int preOrderTraverse(struct treeNode * root, struct sqStack * stackPointer){
    if(root == NULL){
        printf("空树\n");
        return 0;
    }

    printf("前序遍历结果:");
    struct treeNode * temp = root;
    push(stackPointer, temp);

    while(stackPointer->top != 0){
        while(temp != NULL){
            printf("%c ", temp->data);
            temp = temp->lChild;
            if(temp != NULL)
                push(stackPointer, temp);
        }

        temp = pop(stackPointer);
        temp = temp->rChild;
        if(temp != NULL)
            push(stackPointer, temp);
    }
    printf("\n");

    return 1;
}

int inOrderTraverse(struct treeNode * root, struct sqStack * stackPointer){
    if(root == NULL){
        printf("空树\n");
        return 0;
    }

    printf("中序遍历结果:");
    struct treeNode * temp = root;
    push(stackPointer, temp);

    while(stackPointer->top != 0){
        while(temp != NULL){
            temp = temp->lChild;
            if(temp != NULL)
                push(stackPointer, temp);
        }

        temp = pop(stackPointer);
        printf("%c ", temp->data);
        temp = temp->rChild;
        if(temp != NULL)
            push(stackPointer, temp);
    }
    printf("\n");

    return 1;
}