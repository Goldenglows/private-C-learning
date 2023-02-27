#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int strLength(char * Source);
void getNext(char * Target, int * Next);
void index_KMP(char * Source, char * Target, int *Next);

int main(){
	char * Source = (char *)malloc(MAXSIZE * sizeof(char));
	char * Target = (char *)malloc(MAXSIZE * sizeof(char));
	int * Next = (int *)malloc((MAXSIZE + 1) * sizeof(int));
	
	printf("������������");
	scanf("%[^\n]", Source);
	getchar();
	
	printf("������ģʽ����");
	scanf("%[^\n]", Target);
	getchar();
	
	getNext(Target, Next);
	
	index_KMP(Source, Target, Next);
	 
	free(Source);
	free(Target);
	free(Next);
}

int strLength(char * Source){
	int i = 0;
	while(Source[i] != '\0')
		i++;
	
	return i;
}

void getNext(char * Target, int * Next){
	int i = 1;
	Next[1] = 0;
	int j = 0;
	printf("nextֵ���������£�\n");
	printf("1 : %d\n", Next[1]);
	
	while(i < strLength(Target)){
		if(j == 0 || Target[i - 1] == Target[j - 1]){
			++i;
			++j;
			Next[i] = j;
			printf("%d : %d\n", i, Next[i]);
		}
		else
			j = Next[j];
	}
}

void index_KMP(char * Source, char * Target, int *Next){
	int i = 1;
	int j = 1;
	while(i <= strLength(Source) && j <= strLength(Target)){
		if(j == 0 || Source[i - 1] == Target[j - 1]){
			++i;
			++j;
		}
		
		else
			j = Next[j];
	}
	
	if(j > strLength(Target))
		printf("ģʽƥ��ɹ�������λ�ã�%d\n", i - strLength(Target));
		
	else
		printf("ģʽƥ��ʧ��\n");
}
