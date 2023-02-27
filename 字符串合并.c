#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

void strCpy(char * Target, char * Source);
int strLength(char * Source);
int strCmp(char * Target, char * Source);
void conCat(char * Target, char * Source); 
void subString(char * Target, int pos, int len);


int main(){
	char * Target = (char *)malloc(MAXSIZE * sizeof(char));
	char * Source = (char *)malloc(MAXSIZE * sizeof(char));
	
	printf("�������ַ���:");
	scanf("%[^\n]", Source);
	getchar();
	
	printf("�����ַ�������Ϊ��%d\n", strLength(Source));
	
	strCpy(Target, Source);
	printf("���������ַ�����%s\n", Target);
	
	strCmp(Target, Source);
	
	Target[strLength(Target) -1 ] = '\0'; 
	printf("�޸ĺ�Ĵ���%s\n", Target);
	strCmp(Target, Source);
	
	conCat(Target, Source);
	
	
	subString(Source, 2, 7);
	subString(Source, 2, 9);
	

	
	free(Target);
	free(Source);
	return 0;
}


void strCpy(char * Target, char * Source){
	int i = 0;
	while(Source[i] != '\0'){
		Target[i] = Source[i];
		i++;
	}
	Target[i] = '\0';
}


int strLength(char * Source){
	int i = 0;
	while(Source[i] != '\0')
		i++;
	
	return i;
}

int strCmp(char * Target, char * Source){
	int i = 0;
	while(Target[i] != '\0' && Source[i] != '\0'){
		if(Target[i] != Source[i])
			break;
		i++;
	}
	if(Target[i] == '\0' && Source[i] =='\0'){
		printf("�����ַ������\n"); 
		return 1;
	}
		
	else{
		printf("�����ַ��������\n"); 
		return 0;
	}		
}

void conCat(char * Target, char * Source){
	if(strLength(Target) + strLength(Source) >= MAXSIZE)
		printf("�ϲ��󴮳��������洢�ռ䣬�޷��ϲ�\n");
		
	else{
		int i = 0;
		while(Target[i] != '\0')
			i++;
			
		int j = 0;
		while(Source[j] != '\0'){
			Target[i] = Source[j];
			i++;
			j++;
		}
		Target[i] = '\0';
		printf("�ϲ����´�Ϊ��%s\n", Target); 
	} 
}

void subString(char * Target, int pos, int len){
	if(pos + len > strLength(Target))
		printf("��ȡ�Ӵ���������Χ\n");
	else{
		char * subStr = (char *)malloc(MAXSIZE * sizeof(char));
		int i = 0;
		while(i < len){
			subStr[i] = Target[pos];
			i++;
			pos++;
		}
		subStr[i] = '\0';
		printf("�Ӵ�Ϊ��%s\n", subStr);
	}
}

