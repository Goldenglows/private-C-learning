#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10

/*
// 定义队列结构体
typedef struct queue {
    int data[MAX_SIZE];
    int front;  // 队头指针
    int rear;   // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 判断队列是否为空
int isQueueEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

// 判断队列是否已满
int isQueueFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// 入队
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

// 出队
int deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->data[q->front];
    if (q->front == q->rear) {  // 队列只剩下一个元素时
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return x;
}

// 获取队头元素
int getFront(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->data[q->front];
}

// 获取队尾元素
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

//顾客基本信息
struct SqNode {
	int num;
	//序号
	char name[100];
	//顾客姓名
	char identity[100];
	//顾客特殊身份
};

struct SqQueue {
	//队列结构体
	struct SqNode* base;
	//队列首地址
	int front;
	//表头
	int rear;
	//表尾
};

struct SqQueue* InitSqQueue() {
	//初始化循环队列
	struct SqQueue* p = (struct SqQueue*)malloc(sizeof(struct SqQueue));
	//为队列开辟空间
	if (!p) {
		//判断是否分配空间失败
		printf("InitSqQueue()-SqQueue: Malloc failed!\n");
		exit(-1);
	}

	p->base = (struct SqNode*)malloc(MAXSIZE * sizeof(struct SqNode));
	if (!p->base) {
		//判断是否分配空间失败
		printf("InitSqQueue()-SqQueue->base: Malloc failed!\n");
		exit(-1);
	}

	p->front = 0;
	p->rear = 0;

	//初始化队列元素
	for (int i = 0; i < MAXSIZE; i++) {

	}

	return p;

}

int GetLength(struct SqQueue* p) {
	//查看队列中有多少人
	int length = (p->rear - p->front + MAXSIZE) % MAXSIZE;
	//获取队列中的人数
	return length;
}

int inQueue(struct SqQueue* p) {

	if ((p->rear + 1) % MAXSIZE == p->front) {
		//判断是否队列满
		printf("当前预留叫号位已满，无法叫号\n");
		return -1;
	}



	//输入顾客基本信息
	getchar();
	printf("请输入顾客姓/姓名：");
	scanf("%[^\n]", p->base[p->rear].name);
	//取最后一个空出来的空间存放该顾客
	getchar();
	printf("请输入顾客序号：");
	scanf("%d", &p->base[p->rear].num);
	//为顾客定制序号
	getchar();
	printf("您前面还有%d人在等候用餐，请您耐心等候\n", GetLength(p));

	p->rear = (p->rear + 1) % MAXSIZE;
	//移动队尾指针

	return 1;
}

int CallQueue(struct SqQueue* p) { //叫号(出队列)
	if (p->front == p->rear) {     //判断队列中是否有人
		printf("当前无人排队，叫号失败！\n");
		return -1;
	}

	printf("%d号%s先生/女士，到您吃火锅了！\n", p->base[p->front].num, p->base[p->front].name);
	p->front = (p->front + 1) % MAXSIZE;   //移动队头
	return 1;
}

void ShowQueue(struct SqQueue* p) {
	//具体展示当前排队的人数
	if (p->front == p->rear) {
		//判断是否有人
		printf("当前无人排队！\n");
	}
	else {
		printf("当前排队人数为：%d\n", GetLength(p));
		int tmp;
		tmp = p->front;
		while (tmp != p->rear) {
			printf("第%d号：%s先生/女士\n", p->base[tmp].num, p->base[tmp].name);
			tmp = (tmp + 1) % MAXSIZE;
		}
	}
}

void menu() {
	printf("\n");
	printf("              AHU HOT POT              \n");
	printf("               叫号小程序               \n");
	printf("  1.取号\n");
	printf("  2.叫号\n");
	printf("  3.查看排队人数\n");
	printf("  4.查看排队具体情况\n");
	printf("  0.退出小程序\n");
	printf("\n");
	printf("请输入您要进行的操作序号：");
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
			printf("确定退出？\n");
			printf("Yes（输入1）， No（输入其他）\n");
			scanf("%d", &judg);
			if (1) {
				printf("退出中...");
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
			printf("当前排队人数为：%d", GetLength(Qu));
			break;

		case 4:
			ShowQueue(Qu);
			break;

		default:
			printf("暂未开发该功能，请重试。");
			break;

		}
	}
}

