#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct   //* ����һ��ѧ����Ϣ�Ľṹ��
{
    int number;     // *ѧ��ѧ��
    char grade;     // * ѧ���ĳɼ��ȼ�:A B C
    char name[10];  //* ѧ������
}ST;

typedef struct 
{
    ST* p;      //* ����ռ�Ĵ����ַ
    int length; //* ˳���ĳ���
}Sqlist;

char* Get_In(char *arr, int n) //* ����һ��û�л��з������뷽��
{
    char* find;
    char* ret_val;
    ret_val = fgets(arr, n, stdin);
    if(ret_val)
    {
        find = strchr(arr, '\n');
        if(find)
        {
            *find = '\0';
        }
        else
        {
            while(getchar() != '\n')
            continue;
        }
    }
    return ret_val;
}
void searchLength(Sqlist* sq)  //*��ѯ��ǰ˳������Ϣ
{
    int i;
    int j;
    int length;
    ST temp;

    length = sq->length;
    printf("˳�����Ϊ: %d.\n",length);
    for(i = 1 ; i <= length ; i++) //* ð��������������
    {
        for(j = 1 ; j <= length-i ; j++)
        {
            if(sq->p[j].number > sq->p[j+1].number)
            {
                temp = sq->p[j];
                sq->p[j] = sq->p[j+1];
                sq->p[j+1] = temp;
            }
            else
            continue;
        }
    }
}
void Creat_Sqlist(Sqlist *sq, int n) //* ����˳���
{
    if(n > 100 || n < 1)
    printf("ERROR! Please enter the number again!");
    else
    printf("Enter success!\n");
    sq->p = (ST*)malloc((MAXSIZE+1) * sizeof(ST));  //*�����ڴ��ַ
    if(sq->p)
    {
        printf("˳������ɹ�.\n");
    }
    else
    {
        printf("˳�����ʧ��.\n");
    }
    sq->length = n;                 // * ȷ��˳���ĳ���
}
void Getin_Sqlist(Sqlist *sq) //*���ն˸�˳���ֵ
{
    int i;
    printf("������%d��ѧ������Ϣ:(ѧ�� �ɼ��ȼ� ѧ������)\n", sq->length);
    for(i = 1 ; i <= sq->length ; i++)
    {
        scanf("%d %c %s", &(sq->p[i].number), &(sq->p[i].grade), sq->p[i].name);
    }
    printf("�ɹ�����ѧ����Ϣ\n");
}
void Print_Sqlist(Sqlist sq) //* ��ʾ˳����ֵ
{
    int i;
    printf("����Ϊѧ������Ϣ:\n");
    printf("%10s %10s %10s\n","number", "grade", "name");
    for(i = 1 ; i <= sq.length ; i++)
    {
        printf("%12d %6c %10s\n", sq.p[i].number, sq.p[i].grade, sq.p[i].name);
    }
}
int Search_Name(Sqlist sq)  //* �������ֲ��Ҷ�Ӧѧ������Ϣ
{
    int i;
    int record = 0;
    char name[10]; //* ����ѧ��������
    
    printf("������ѧ��������:\n");
    scanf("%s", name);
    for(i = 1 ; i <= sq.length ; i++)
    {
        if(strcmp(name, sq.p[i].name) == 0)   //* ���ܱȽ�name��sq->nameֱ�ӱȽ�, ��Ϊ�����Ƚϵ��ǵ�ַ���������ַ���
        {
            record = i;
            break;
        }
        else
        continue;
    }
    return record;
}
void Search_grade(Sqlist sq)
{
    int i;
    int record = 0;
    char grade;
    int length = sq.length;
    
    fflush(stdin); //* ��ջ���������Ȼ����һ���ַ�ʱ���ȡ�������еĻ��з�
    printf("�������ѯ�ĵȼ�: \n");
    scanf("%c", &grade);
    for(i = 1 ; i <= sq.length ; i++)
    {
        if(sq.p[i].grade == grade)
        {
            record = 1;
            printf("�ȼ�Ϊ%c��ѧ��Ϊ%s\n", sq.p[i].grade, sq.p[i].name);
        }
    }
    if(record == 0)
    printf("��%c�ȼ���ѧ��\n",grade);

    return;
}
void Add_info(Sqlist *sq, int increase)
{
    int i;
    int length;
    length = sq->length;
    sq->length = length + increase; //* �������Ա�ĳ���
    printf("������%d��ѧ������Ϣ:(ѧ�� �ɼ��ȼ� ѧ������)\n", increase);
    for(i = length+1 ; i <= sq->length ; i++)
    {
        scanf("%d %c %s", &(sq->p[i].number), &(sq->p[i].grade), &(sq->p[i].name));
    }
    printf("�ɹ�������Ϣ.\n");
}
void Delete_info(Sqlist* sq)
{
    int i;
    int record;

    record = Search_Name(*sq);
    for(i = record ; i < sq->length ; i++)
    {
        sq->p[i] = sq->p[i+1];
    }
    sq->length = sq->length - 1; //* ���ȼ�һ
    printf("�ɹ�ɾ��!\n");
}
int main()
{
    printf("0. ��ѯ��ǰ˳���ĳ���\n");
    printf("1. ����˳���\n");
    printf("2. ����ѧ����Ϣ��\n");
    printf("3. ��ʾѧ������Ϣ��\n");
    printf("4. ����ѧ�����ֲ�����Ϣ��\n");
    printf("5. ����ѧ���ȼ�������Ϣ��\n");
    printf("6. ���ѧ������Ϣ��\n");
    printf("7. ɾ��ĳ��ѧ������Ϣ��\n\n");                                 

    Sqlist p;  //* ������Ϣ�Ľڵ�
    int record;
    int choose = 1;
    int num;     //* ѧ��������
    int increase; //* ���ѧ���ĸ���
    int pos; //* ��Ҫɾ��ѧ���Ķ�Ӧ��λ��

    while(choose != -1)
    {
        printf("��ѡ��(����-1�˳�����):\n");
        scanf("%d", &choose);

        switch(choose)
        {
            case -1:
            printf("�ɹ��˳�����.\n");
            break;

            case 0:
            searchLength(&p);  //* ��ѯ��ǰ˳���ĳ���
            break;

            case 1:
            printf("Please enter the number of the students: \n"); //* �����ʼѧ���ĸ���
            scanf("%d", &num);
            Creat_Sqlist(&p, num); //* ����˳���
            break;

            case 2:
            Getin_Sqlist(&p); //* Ϊ˳���������Ϣ
            break;

            case 3:
            Print_Sqlist(p); //* ��ʾ˳������Ϣ
            break;

            case 4:
            record = Search_Name(p);  //* �������ֲ��Ҷ�Ӧ����Ϣ
            if(record != 0)
            {
                printf("���ҳɹ�!\n");
                printf("%s��ѧ��Ϊ%d\n",p.p[record].name, p.p[record].number);
                printf("%s�ĳɼ��ȼ�Ϊ%c\n",p.p[record].name, p.p[record].grade);
            }
            else if(record == 0)
            {
                printf("û�в鵽��ѧ��\n");
            }
            break;

            case 5:
            Search_grade(p);
            break;

            case 6 :          //* ����ѧ������Ϣ
            printf("����������ѧ����Ϣ�ĸ���:\n");
            scanf("%d", &increase);
            Add_info(&p, increase);
            break;

            case 7:     //*  ����ѧ��������ɾ��ѧ������Ϣ
            Delete_info(&p);
            break;
            
            default :
            printf("����������.\n");
        }
    }
}
