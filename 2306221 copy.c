#include <stdio.h>
#define maxsize 5  // 页面框的大小

// 定义栈结构
struct Stack {
    int data[maxsize];
    int top;
};

// 初始化栈
void initialize(struct Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// 判断栈是否已满
int isFull(struct Stack *s) {
    return (s->top == maxsize - 1);
}

// 入栈操作
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// 出栈操作
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("栈已空，无法出栈\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// LRU页面置换算法
void LRU(int pages[], int n) {
    struct Stack stack;
    initialize(&stack);
    int i, j, index;
    int pages = 0;

    // 遍历页面请求
    for (i = 0; i < n; i++) {
        index = pages[i];
        
        // 检查页面是否已在栈中
        int found = 0;
        for (j = stack.top; j >= 0; j--) {
            if (stack.data[j] == index) {
                found = 1;
                break;
            }
        }

        // 页面不在栈中，发生缺页中断，进行页面置换
        if (!found) {
            pages++;
            
            // 栈已满，移除最久未使用的页面
            if (isFull(&stack)) {
                int oldpage = pop(&stack);
                printf("置换页面 %d\n", oldpage);
            }
            
            // 将新页面加入栈顶
            push(&stack, index);
        }

        // 输出当前页面状态
        printf("当前页面状态：");
        for (j = stack.top; j >= 0; j--) {
            printf("%d ", stack.data[j]);
        }
        printf("\n");
    }

    printf("总缺页次数：%d\n", pages);
}

int main() {
    int n;
    printf("请输入页面请求序列长度：");
    scanf("%d", &n);

    int pages[n];
    printf("请输入页面请求序列：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    LRU(pages, n);

    return 0;
}