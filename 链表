#include<stdio.h>
#include<stdlib.h>

struct linkListNode{
	char name[100];
	int number;
	
	struct linkListNode * nextNode;
};

struct linkListNode * InitializeLinkListNode();
void InitializeStuInfo(struct linkListNode * headNode);
void DispLinkList(struct linkListNode * headNode); 
struct linkListNode * GetElem(struct linkListNode * headNode, int position); 
void ListInsert(struct linkListNode * headNode, int position, struct linkListNode ln); 
void ListDelete(struct linkListNode * headNode, int position);

int main(){
	struct linkListNode *headNode = InitializeLinkListNode();
	
	InitializeStuInfo(headNode);
	
	DispLinkList(headNode);
	
	struct linkListNode * p = GetElem(headNode, 1);
	printf("Name: %s | Number: %d\n", p->name, p->number);
	
	struct linkListNode newNode;
	printf("    Name:");
	scanf("%[^\n]", newNode.name);
	printf("    Number:");
	scanf("%d", &newNode.number);
	getchar();
	
	ListInsert(headNode, 0, newNode);
	DispLinkList(headNode);
	
	printf("\n\n");
	ListDelete(headNode, 1);
	DispLinkList(headNode);	
} 

struct linkListNode * InitializeLinkListNode(){
	
	struct linkListNode * p = (struct linkListNode *)malloc(sizeof(struct linkListNode));
	p->nextNode =NULL;
	return p;
}

void InitializeStuInfo(struct linkListNode * headNode){
	for(int i = 0; i < 3; i++){
		struct linkListNode * newNode = (struct linkListNode *)malloc(sizeof(struct linkListNode));
		headNode->nextNode = newNode;
		
		printf("Initialize student node %d\n", i);
		printf("    Name:");
		scanf("%[^\n]", newNode->name);
		printf("    Number:");
		scanf("%d", &newNode->number);
		getchar();
		
		headNode = headNode->nextNode;
	}
}

void DispLinkList(struct linkListNode * headNode){
	while(headNode->nextNode != NULL){
		headNode = headNode->nextNode;
		
		printf("Name: %s | Number: %d\n", headNode->name, headNode->number);
	}
}

struct linkListNode * GetElem(struct linkListNode * headNode, int position){
	struct linkListNode * p = headNode->nextNode;
	int j = 0;
	while(p != NULL && j < position){
		p = p->nextNode;
		j++;
	} 
	
	if(p != NULL && j == position)
		return p;
	
	else
		return NULL;
}

void ListInsert(struct linkListNode * headNode, int position, struct linkListNode ln){
	struct linkListNode * newNode = (struct linkListNode *)malloc(sizeof(struct linkListNode));
	newNode->number = ln.number;
	newNode->nextNode = NULL;
	int k = 0;
	while(ln.name[k] != '\0'){
		newNode->name[k] = ln.name[k];
		k++;
	}
	ln.name[k] = '\0';
	
	struct linkListNode * p = headNode;
	int j = 0;
	
	while(p != NULL && j < position){
		p = p->nextNode;
		j++;
	}
	
	if(p != NULL){
		newNode->nextNode = p->nextNode;
		p->nextNode = newNode;
	}
}

void ListDelete(struct linkListNode * headNode, int position){
	struct linkListNode * p = headNode;
	int j = 0;
	
	while(p != NULL && j < position){
		p = p->nextNode;
		j++;
	}
	
	if(p != NULL){
		struct linkListNode * q = p->nextNode;
		p->nextNode = q->nextNode;
		free(q);
	}
		
}
