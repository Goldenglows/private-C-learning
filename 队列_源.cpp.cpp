#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10

/*
// ������нṹ��
typedef struct queue {
    int data[MAX_SIZE];
    int front;  // ��ͷָ��
    int rear;   // ��βָ��
} Queue;

// ��ʼ������
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

// �ж϶����Ƿ�����
int isQueueFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// ���
void enQueue(Queue* q, int x) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = x;
}

// ����
int deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->data[q->front];
    if (q->front == q->rear) {  // ����ֻʣ��һ��Ԫ��ʱ
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return x;
}

// ��ȡ��ͷԪ��
int getFront(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->data[q->front];
}

// ��ȡ��βԪ��
int getRear(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->data[q->rear];
}

int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);

    printf("Queue front: %d\n", getFront(&q));
    printf("Queue rear: %d\n", getRear(&q));

    printf("Dequeued: %d\n", deQueue(&q));
    printf("Queue front: %d\n", getFront(&q));
    printf("Queue rear: %d\n", getRear(&q));

    enQueue(&q, 4);
    enQueue(&q, 5);

    printf("Queue front: %d\n", getFront(&q));
    printf("Queue rear: %d\n", getRear(&q));

    printf("Dequeued: %d\n", deQueue(&q));
    printf("Queue front: %d\n", getFront(&q));
    printf("Queue rear: %d\n", getRear(&q));

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

//�˿ͻ�����Ϣ
struct SqNode {
	int num;
	//���
	char name[100];
	//�˿�����
	char identity[100];
	//�˿��������
};

struct SqQueue {
	//���нṹ��
	struct SqNode* base;
	//�����׵�ַ
	int front;
	//��ͷ
	int rear;
	//��β
};

struct SqQueue* InitSqQueue() {
	//��ʼ��ѭ������
	struct SqQueue* p = (struct SqQueue*)malloc(sizeof(struct SqQueue));
	//Ϊ���п��ٿռ�
	if (!p) {
		//�ж��Ƿ����ռ�ʧ��
		printf("InitSqQueue()-SqQueue: Malloc failed!\n");
		exit(-1);
	}

	p->base = (struct SqNode*)malloc(MAXSIZE * sizeof(struct SqNode));
	if (!p->base) {
		//�ж��Ƿ����ռ�ʧ��
		printf("InitSqQueue()-SqQueue->base: Malloc failed!\n");
		exit(-1);
	}

	p->front = 0;
	p->rear = 0;

	//��ʼ������Ԫ��
	for (int i = 0; i < MAXSIZE; i++) {

	}

	return p;

}

int GetLength(struct SqQueue* p) {
	//�鿴�������ж�����
	int length = (p->rear - p->front + MAXSIZE) % MAXSIZE;
	//��ȡ�����е�����
	return length;
}

int inQueue(struct SqQueue* p) {

	if ((p->rear + 1) % MAXSIZE == p->front) {
		//�ж��Ƿ������
		printf("��ǰԤ���к�λ�������޷��к�\n");
		return -1;
	}



	//����˿ͻ�����Ϣ
	getchar();
	printf("������˿���/������");
	scanf("%[^\n]", p->base[p->rear].name);
	//ȡ���һ���ճ����Ŀռ��Ÿù˿�
	getchar();
	printf("������˿���ţ�");
	scanf("%d", &p->base[p->rear].num);
	//Ϊ�˿Ͷ������
	getchar();
	printf("��ǰ�滹��%d���ڵȺ��òͣ��������ĵȺ�\n", GetLength(p));

	p->rear = (p->rear + 1) % MAXSIZE;
	//�ƶ���βָ��

	return 1;
}

int CallQueue(struct SqQueue* p) { //�к�(������)
	if (p->front == p->rear) {     //�ж϶������Ƿ�����
		printf("��ǰ�����Ŷӣ��к�ʧ�ܣ�\n");
		return -1;
	}

	printf("%d��%s����/Ůʿ�������Ի���ˣ�\n", p->base[p->front].num, p->base[p->front].name);
	p->front = (p->front + 1) % MAXSIZE;   //�ƶ���ͷ
	return 1;
}

void ShowQueue(struct SqQueue* p) {
	//����չʾ��ǰ�Ŷӵ�����
	if (p->front == p->rear) {
		//�ж��Ƿ�����
		printf("��ǰ�����Ŷӣ�\n");
	}
	else {
		printf("��ǰ�Ŷ�����Ϊ��%d\n", GetLength(p));
		int tmp;
		tmp = p->front;
		while (tmp != p->rear) {
			printf("��%d�ţ�%s����/Ůʿ\n", p->base[tmp].num, p->base[tmp].name);
			tmp = (tmp + 1) % MAXSIZE;
		}
	}
}

void menu() {
	printf("\n");
	printf("              AHU HOT POT              \n");
	printf("               �к�С����               \n");
	printf("  1.ȡ��\n");
	printf("  2.�к�\n");
	printf("  3.�鿴�Ŷ�����\n");
	printf("  4.�鿴�ŶӾ������\n");
	printf("  0.�˳�С����\n");
	printf("\n");
	printf("��������Ҫ���еĲ�����ţ�");
}

int main() {

	struct SqQueue* Qu = InitSqQueue();

	while (1) {
		menu();

		int _num;
		scanf("%d", &_num);

		switch (_num) {
		case 0:
			int judg;
			printf("ȷ���˳���\n");
			printf("Yes������1���� No������������\n");
			scanf("%d", &judg);
			if (1) {
				printf("�˳���...");
				free(Qu->base);
				free(Qu);
				return 0;
				break;
			}
			else
				break;

		case 1:
			inQueue(Qu);
			break;

		case 2:
			CallQueue(Qu);
			break;

		case 3:
			printf("��ǰ�Ŷ�����Ϊ��%d", GetLength(Qu));
			break;

		case 4:
			ShowQueue(Qu);
			break;

		default:
			printf("��δ�����ù��ܣ������ԡ�");
			break;

		}
	}
}

