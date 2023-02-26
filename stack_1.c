#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct stack_1
{
    /* data */
    int *base;//栈底元素
    int *top;//栈顶元素
    int len;//栈的长度
};

void Initstack(struct stack_1 *s){
    int *q = (int *)malloc(MAXSIZE * sizeof(int));
    s->base = q;
    s->top = q;
    //初始化时，栈顶和栈底的指针要都指向一起
    s->len = MAXSIZE;
}

int Push_stack(struct stack_1 * s,int element){
    //入栈
    if(s->top - s->base == s->len)
    //栈顶指针到栈底指针的长度为栈的总长度
    //判满
    {
        printf("Stack is full\n");
        return -1;
    }

    *s->top++ = element;
    return 0;
}

int Pop_stack(struct stack_1 *s, int element){
    //出栈
    if(s->top == s->base){
        //当栈顶指针和栈底指针指向了一起，
        //就是代表栈内为空
        //判空
        printf("Stack is empty\n");
        return -1;
    }

    return *--s->top;
}

int Get_top(struct stack_1 *s){
    //取栈最上面的数值
    if (s->top == s->base){
        //判空
        printf("Stack is empty");
        return -1;
    }

    return *(s->top-1);
}

void Display_stack(struct stack_1 *s){
    //列举出栈中的所有元素
    printf("栈中的元素如下：");
    while ( s->top != s->base){
        printf("%d\n",*--s->top);
    }
}
