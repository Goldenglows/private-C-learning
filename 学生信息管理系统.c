#include <stdio.h>
#include <stdlib.h>

//最大学生人数 
#define MAXSTUNUM 100

//学生节点，存储单个学生信息 
struct stuNode{
	//姓名 
	char name[100];
	//学号 
	int sutNum;
	//年龄 
	int age;
};

//学生顺序表，存储所有学生信息 
struct stuList{
	//表头指针 
	struct stuNode * elem;
	//存储学生信息数 
	int length;
};

void InitList(struct stuList * list); 

void InitStuInfo(struct stuList * list);

void DispList(struct stuList * list);

struct stuNode GetElem(struct stuList * list, int i); 

int LocateElem(struct stuList * list, int num);

void ListInsert(struct stuList *list, int i, struct stuNode sn);


int main(){
	
	struct stuList * list =(struct stuList *)malloc(sizeof(struct stuList));
	InitList(list);
	
	InitStuInfo(list);
	
	DispList(list);
	
	struct stuNode sn;
	sn = GetElem(list, 1);
	printf("Name: %s | Number: %d | Age: %d\n", sn.name, sn.sutNum, sn.age);
	
	int locate = LocateElem(list, 1003);
	printf("%d\n", locate);
	
	
	printf("    Name:");
	scanf("%[^\n]", sn.name);
	printf("    Number:");
	scanf("%d", &sn.sutNum);
	printf("    Age:");
	scanf("%d", &sn.age);
	getchar();
	
	ListInsert(list, 0, sn);
	
	DispList(list);

	return 0;
}

void InitList(struct stuList * list){
	list->elem = (struct stuNode *)malloc(MAXSTUNUM * sizeof(struct stuNode));
	list->length = 0; 
}

void InitStuInfo(struct stuList * list){
	for(int i = 0; i < 3; i ++){
		printf("Initialize student node %d\n", list->length);
		printf("    Name:");
		scanf("%[^\n]", list->elem[list->length].name);
		printf("    Number:");
		scanf("%d", &list->elem[list->length].sutNum);
		printf("    Age:");
		scanf("%d", &list->elem[list->length].age);
		getchar();
		list->length ++;
	}
}

void DispList(struct stuList * list){
	if(list->length == 0)
		printf("Empty list\n");
		
	else{
		for(int i = 0; i < list->length; i++){
			printf("Student No. %d: Name: %s | Number: %d | Age: %d\n", i, list->elem[i].name, list->elem[i].sutNum, list->elem[i].age);
		}
	}
}

struct stuNode GetElem(struct stuList * list, int i){
	if(i < 0 || i >= list->length){
		printf("Error parameter\n");
		exit(-1);
	}
	
	return list->elem[i];
}

int LocateElem(struct stuList * list, int num){
	if(list->length == 0){
		printf("Empty list\n");
		return -1;
	}
	
	int i;
	for(i = 0; i < list->length; i++){
		if(num == list->elem[i].sutNum)
			return i;
	}
	
	return -2;
}

void ListInsert(struct stuList *list, int i, struct stuNode sn){
	if(i < 0 || i > list->length){
		printf("Error parameter\n");
		exit(-1);
	}
	
	int j;
	for(j = list->length; j > i; j--){
		list->elem[j].sutNum  = list->elem[j - 1].sutNum;
		list->elem[j].age = list->elem[j - 1].age;
		
		int k = 0;
		while(list->elem[j - 1].name[k] != '\0'){
			list->elem[j].name[k] = list->elem[j - 1].name[k];
			k++;
		}
		list->elem[j].name[k] = '\0';
	}  
	
	list->elem[i].age = sn.age;
	list->elem[i].sutNum = sn.sutNum;
	int k = 0;
	while(sn.name[k] != '\0'){
		list->elem[i].name[k] = sn.name[k];
		k++;
	}
	list->elem[i].name[k] = '\0';