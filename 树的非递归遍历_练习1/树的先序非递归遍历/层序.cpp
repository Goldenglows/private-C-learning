#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 定义队列节点
struct QueueNode {
    struct TreeNode* val;
    struct QueueNode* next;
};

// 定义队列结构体
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// 初始化队列
void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 入队
void enQueue(struct Queue* queue, struct TreeNode* val) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->val = val;
    newNode->next = NULL;
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队
struct TreeNode* deQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    else {
        struct QueueNode* temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        struct TreeNode* val = temp->val;
        free(temp);
        return val;
    }
}

// 获取队列首元素
struct TreeNode* getFront(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    else {
        return queue->front->val;
    }
}

// 判断队列是否为空
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// 层序遍历
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // 初始化队列并将根节点入队
    struct Queue queue;
    initQueue(&queue);
    enQueue(&queue, root);
    // 遍历队列
    while (!isQueueEmpty(&queue)) {
        // 获取当前层的节点数量
        int levelSize = 0;
        int size = queue.rear - queue.front + 1;
        // 遍历当前层的节点
        for (int i = 0; i < size; i++) {
            struct TreeNode* curNode = getFront(&queue);
            printf("%d ", curNode->val);
            deQueue(&queue);
            if (curNode->left) {
                enQueue(&queue, curNode->left);
                levelSize++;
            }
            if (curNode->right) {
                enQueue(&queue, curNode->right);
                levelSize++;
            }
        }
        printf("\n");
    }
}
