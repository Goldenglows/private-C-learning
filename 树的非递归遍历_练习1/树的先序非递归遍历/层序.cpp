#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ������нڵ�
struct QueueNode {
    struct TreeNode* val;
    struct QueueNode* next;
};

// ������нṹ��
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// ��ʼ������
void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// ���
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

// ����
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

// ��ȡ������Ԫ��
struct TreeNode* getFront(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    else {
        return queue->front->val;
    }
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// �������
void levelOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // ��ʼ�����в������ڵ����
    struct Queue queue;
    initQueue(&queue);
    enQueue(&queue, root);
    // ��������
    while (!isQueueEmpty(&queue)) {
        // ��ȡ��ǰ��Ľڵ�����
        int levelSize = 0;
        int size = queue.rear - queue.front + 1;
        // ������ǰ��Ľڵ�
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
