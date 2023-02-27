
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef struct ST {
	char data[Maxsize];
	int  top;
} Stack;

void Init(Stack *L) {
	L->top = -1;
}

void Push(Stack *L, char x) {
	if (L->top >= Maxsize) {
		return;
	}
	L->top++;
	L->data[L->top] = x;
}

int Empty(Stack L) { //ÅÐ¿Õ
	if (L.top == -1) {
		return 1;//Îª¿Õ·µ»Ø1
	}
	return 0;    //²»Îª¿Õ·µ»Ø0
}

void Print(Stack L) {
	for (int i = L.top; i > -1; i--) {
		printf("%c   ", L.data[i]);
	}
}

void Pop(Stack *L) {
	if (L->top == -1) {
		return;
	}
	L->top--;
}

char Get(Stack L) {
	return L.data[L.top];
}

int main() {
	Stack L;
	char s[100];
	while (gets(s)) {
		Init(&L);
		int flag = 1;
		//printf("%s",s);
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				if (L.top < Maxsize) {
					char x = s[i];
					Push(&L, x);
				}

			} else if (s[i] == ')') {

				if (Empty(L)) {
					flag = 0;
					break;
				} else {
					if (Get(L) == '(') {
						Pop(&L);
					} else {
						flag = 0;
						break;
					}
				}
			} else if (s[i] == '}') {

				if (Empty(L)) {
					flag = 0;
					break;
				} else {
					if (Get(L) == '{') {
						Pop(&L);
					} else {
						flag = 0;
						break;
					}
				}
			} else if (s[i] == ']') {
				if (Empty(L)) {
					flag = 0;
					break;
				} else {
					if (Get(L) == '[') {
						Pop(&L);
					} else {
						flag = 0;
						break;
					}
				}
			}
		}
		if (!Empty(L)) {
			flag = 0;
		}
		if (flag == 1 && Empty(L)) {
			printf("Æ¥Åä³É¹¦\n");
		} else {
			printf("Æ¥ÅäÊ§°Ü\n");
		}
	}
	return 0;
}