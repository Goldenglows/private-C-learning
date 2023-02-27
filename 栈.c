#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

struct SqStack{
    int * base;
    int * top;
    int stackSize;
};

void InitStack(struct SqStack * s);
int Push(struct SqStack * s, int data);
void DispStack(struct SqStack * s);
int GetTop(struct SqStack *s);
int Pop(struct SqStack *s);

int main(){
	struct SqStack *s = (struct SqStack *)malloc(sizeof(struct SqStack));
	InitStack(s); 
	
	for(int i = 0; i < 8; i++){
		Push(s, i);
	}
	
	DispStack(s);
	
	printf("Get top: %d\n", GetTop(s));
	
	for(int i = 0; i < 8; i++){
		printf("Stack pop: %d\n", Pop(s));
	}
	
	free(s);
	return 0;
}



void InitStack(struct SqStack * s){
    int * p = (int *)malloc(MAXSIZE * sizeof(int));
    s->base = p;
    s->top = p;
    s->stackSize = MAXSIZE;
}

int Push(struct SqStack *s, int data){
	if(s->top - s->base == s->stackSize){
		printf("Failed to push data:%d in stack, stack is full\n", data);
		return -1;
	}
	
	*s->top ++ = data;
	
	printf("Push data: %d in stack\n", data);
	return 0;
}

void DispStack(struct SqStack *s){
	int * p = s->top;
	while(p != s->base){
		printf("%d\n", *--p);
	}
}

int GetTop(struct SqStack *s){
	if(s->top == s->base){
		printf("Stack is empty\n");
		return -1;
	}
	
	return *(s->top - 1);
}

int Pop(struct SqStack *s){
	if(s->top == s->base){
		printf("Stack is empty\n");
		return -1;
	}
	
	return * --s->top;
}
