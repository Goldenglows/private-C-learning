#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct   //* 定义一个学生信息的结构体
{
    int number;     // *学生学号
    char grade;     // * 学生的成绩等级:A B C
    char name[10];  //* 学生名字
}ST;

typedef struct 
{
    ST* p;      //* 分配空间的储存基址
    int length; //* 顺序表的长度
}Sqlist;

char* Get_In(char *arr, int n) //* 构造一个没有换行符的输入方法
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
void searchLength(Sqlist* sq)  //*查询当前顺序表的信息
{
    int i;
    int j;
    int length;
    ST temp;

    length = sq->length;
    printf("顺序表长度为: %d.\n",length);
    for(i = 1 ; i <= length ; i++) //* 冒泡排序整理数据
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
void Creat_Sqlist(Sqlist *sq, int n) //* 创建顺序表
{
    if(n > 100 || n < 1)
    printf("ERROR! Please enter the number again!");
    else
    printf("Enter success!\n");
    sq->p = (ST*)malloc((MAXSIZE+1) * sizeof(ST));  //*分配内存基址
    if(sq->p)
    {
        printf("顺序表创建成功.\n");
    }
    else
    {
        printf("顺序表创建失败.\n");
    }
    sq->length = n;                 // * 确定顺序表的长度
}
void Getin_Sqlist(Sqlist *sq) //*从终端给顺序表赋值
{
    int i;
    printf("请输入%d个学生的信息:(学号 成绩等级 学生名字)\n", sq->length);
    for(i = 1 ; i <= sq->length ; i++)
    {
        scanf("%d %c %s", &(sq->p[i].number), &(sq->p[i].grade), sq->p[i].name);
    }
    printf("成功输入学生信息\n");
}
void Print_Sqlist(Sqlist sq) //* 显示顺序表的值
{
    int i;
    printf("以下为学生的信息:\n");
    printf("%10s %10s %10s\n","number", "grade", "name");
    for(i = 1 ; i <= sq.length ; i++)
    {
        printf("%12d %6c %10s\n", sq.p[i].number, sq.p[i].grade, sq.p[i].name);
    }
}
int Search_Name(Sqlist sq)  //* 根据名字查找对应学生的信息
{
    int i;
    int record = 0;
    char name[10]; //* 储存学生的名字
    
    printf("请输入学生的名字:\n");
    scanf("%s", name);
    for(i = 1 ; i <= sq.length ; i++)
    {
        if(strcmp(name, sq.p[i].name) == 0)   //* 不能比较name和sq->name直接比较, 因为这样比较的是地址，而不是字符串
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
    
    fflush(stdin); //* 清空缓冲区，不然输入一个字符时会读取缓冲区中的换行符
    printf("请输入查询的等级: \n");
    scanf("%c", &grade);
    for(i = 1 ; i <= sq.length ; i++)
    {
        if(sq.p[i].grade == grade)
        {
            record = 1;
            printf("等级为%c的学生为%s\n", sq.p[i].grade, sq.p[i].name);
        }
    }
    if(record == 0)
    printf("无%c等级的学生\n",grade);

    return;
}
void Add_info(Sqlist *sq, int increase)
{
    int i;
    int length;
    length = sq->length;
    sq->length = length + increase; //* 更新线性表的长度
    printf("请输入%d个学生的信息:(学号 成绩等级 学生名字)\n", increase);
    for(i = length+1 ; i <= sq->length ; i++)
    {
        scanf("%d %c %s", &(sq->p[i].number), &(sq->p[i].grade), &(sq->p[i].name));
    }
    printf("成功输入信息.\n");
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
    sq->length = sq->length - 1; //* 长度减一
    printf("成功删除!\n");
}
int main()
{
    printf("0. 查询当前顺序表的长度\n");
    printf("1. 创建顺序表。\n");
    printf("2. 输入学生信息。\n");
    printf("3. 显示学生的信息。\n");
    printf("4. 根据学生名字查找信息。\n");
    printf("5. 根据学生等级查找信息。\n");
    printf("6. 添加学生的信息。\n");
    printf("7. 删除某个学生的信息。\n\n");                                 

    Sqlist p;  //* 储存信息的节点
    int record;
    int choose = 1;
    int num;     //* 学生的人数
    int increase; //* 添加学生的个数
    int pos; //* 想要删除学生的对应的位置

    while(choose != -1)
    {
        printf("请选择(输入-1退出程序):\n");
        scanf("%d", &choose);

        switch(choose)
        {
            case -1:
            printf("成功退出程序.\n");
            break;

            case 0:
            searchLength(&p);  //* 查询当前顺序表的长度
            break;

            case 1:
            printf("Please enter the number of the students: \n"); //* 输入初始学生的个数
            scanf("%d", &num);
            Creat_Sqlist(&p, num); //* 创建顺序表
            break;

            case 2:
            Getin_Sqlist(&p); //* 为顺序表输入信息
            break;

            case 3:
            Print_Sqlist(p); //* 显示顺序表的信息
            break;

            case 4:
            record = Search_Name(p);  //* 根据名字查找对应的信息
            if(record != 0)
            {
                printf("查找成功!\n");
                printf("%s的学号为%d\n",p.p[record].name, p.p[record].number);
                printf("%s的成绩等级为%c\n",p.p[record].name, p.p[record].grade);
            }
            else if(record == 0)
            {
                printf("没有查到此学生\n");
            }
            break;

            case 5:
            Search_grade(p);
            break;

            case 6 :          //* 增加学生的信息
            printf("请输入增加学生信息的个数:\n");
            scanf("%d", &increase);
            Add_info(&p, increase);
            break;

            case 7:     //*  根据学生的名字删除学生的信息
            Delete_info(&p);
            break;
            
            default :
            printf("请重新输入.\n");
        }
    }
}
