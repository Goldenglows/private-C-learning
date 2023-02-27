#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 5

//病人挂号基本信息
struct SqNode{
    //挂号
    int Num;
    //姓名
    char Name[100];
    //病例
    char Description[10000];
};

//循环队列结构体
struct SqQueue{
    //实际存储病人信息队列的首地址
    struct SqNode * base;
    //表头
    int front;
    //表尾
    int rear;
};

//初始化循环队列
struct SqQueue * InitSqQueue();
//病人报到处理函数
int EnSqQueue(struct SqQueue * p);
//取排队人数
int GetSqQueueLength(struct SqQueue *p);
//打印排队病人基本信息
void DispSqQueue(struct SqQueue *p);
//医生叫号
int DeSqQueue(struct SqQueue *p);

int main(int argc, char ** argv){
    //初始化循环队列
    struct SqQueue * Queue = InitSqQueue();

    while(1){
        printf("-----------------------------------\n");
        printf("              主菜单                \n");
        printf("           1. 病人报到              \n");
        printf("           2. 医生叫号              \n");
        printf("           3. 排队人数              \n");
        printf("           4. 排队病人基本信息        \n");
        printf("           0. 退出                  \n");
        printf("-----------------------------------\n");
        printf("输入菜单号(1, 2, 3, 4, 0)：");

        //获取用户指令
        int Ins;
        scanf("%d", &Ins);

        switch (Ins)
        {
        case 1:
            EnSqQueue(Queue);
            break;

        case 2:
            DeSqQueue(Queue);
            break;
        
        case 3:
            GetSqQueueLength(Queue);
            break;

        case 4:
            DispSqQueue(Queue);
            break;

        case 0:
            printf("退出软件\n");
            free(Queue->base);
            free(Queue);
            return 0;
            break;
        
        default:
            printf("输入菜单号有误,请重新输入:\n");
            break;
        }

    }

}

//初始化循环队列
struct SqQueue * InitSqQueue(){
    //创建循环队列结构体
    struct SqQueue * p = (struct SqQueue *)malloc(sizeof(struct SqQueue));
    if(!p){
        printf("InitSqQueue()-SqQueue: Malloc failed!\n");
        exit(-1);
    }

    //分配存储排队病人基本信息内存空间
    p->base = (struct SqNode *)malloc(MAXSIZE * sizeof(struct SqNode));
    if(!p->base){
        printf("InitSqQueue()-SqQueue->base: Malloc failed!\n");
        exit(-1);
    }

    //初始化队头队尾
    p->front = 0;
    p->rear = 0;

    return p;
}

//病人报到处理函数
int EnSqQueue(struct SqQueue * p){
    //判断队列满
    if((p->rear + 1) % MAXSIZE == p->front){
        printf("排队队列满，无法报到\n");
        return - 1;
    }
    
    //输入入队病人基本信息
    getchar();
    printf("请输入病人姓名：");
    scanf("%[^\n]",p->base[p->rear].Name);
    getchar();
    printf("请输入病人挂号号码：");
    scanf("%d", &p->base[p->rear].Num);
    getchar();
    //可以输入病人病例，但没必要

    //移队尾
    p->rear = (p->rear + 1) % MAXSIZE;
    return 1;
}

//取排队人数
int GetSqQueueLength(struct SqQueue *p){
    int length = (p->rear - p->front + MAXSIZE) % MAXSIZE;
    printf("当前排队人数：%d\n", length);
    return length;
}

//打印排队病人基本信息
void DispSqQueue(struct SqQueue *p){
    //空队列处理
    if(p->front == p->rear){
        printf("当前没有病人排队!\n");
    }

    //非空队列处理
    else{
        printf("当前有%d名病人排队，病人信息如下：\n", GetSqQueueLength(p));

        int temp = p->front;
        while(temp != p->rear){
            printf("Name: %s | Number: %d\n", p->base[temp].Name, p->base[temp].Num);
            temp = (temp + 1) % MAXSIZE;
        }
    }
}

//医生叫号
int DeSqQueue(struct SqQueue *p){
    //队列判空
    if(p->front == p->rear){
        printf("没有病人排队，叫号失败！\n");
        return -1;
    }

    //病人出队列
    printf("请病人：%s，挂号号码：%d进入就诊室\n",p->base[p->front].Name, p->base[p->front].Num);
    p->front = (p->front + 1) % MAXSIZE;
    return 1;
}
