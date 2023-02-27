#include<iostream>
using namespace std;

typedef int Status;


//散列表的查找
//开放地址法散列表的存储表示
#define m 20 //散列表的表长
#define NULLKEY 0 //单元为空的标记
#define OK 1
#define OVERFLOW -1

typedef struct
{
	int *elem;//数据元素存储基址，动态分配数组
	int count;//当前数据元素个数
}HashTable;


Status InitHashTable(HashTable &HT)
{//初始化hash表
	int i;
	
	HT.elem=new int[m];//散列表的表长
	if(!HT.elem)
		exit(OVERFLOW);//存储分配失败
	for(i=0;i<m;i++)
		HT.elem[i]=NULLKEY;//单元为空的标记
	HT.count=0;//当前元素个数为0
	return OK;
}

int Hash(int key)
{//获取位置下标
	return key%13;
}

//hash表的建立
void InsertHash(HashTable &HT,int key)
{
	int num=1;
	int index=Hash(key);//位置下标

	while(HT.elem[index]!=NULLKEY)//有数据
	{
		index=Hash(Hash(key)+num);
		num++;
	}
	HT.elem[index]=key;
}

		


//散列表的查找
int SearchHash(HashTable HT,int key)
{//在散列表中查找关键字为key的元素，若查找成功，返回单元标号，否则返回-1
	int index;
	index=Hash(key);//根据散列函数H(key)计算散列地址
	int i;
	if(HT.elem[index]==NULLKEY)//若单元index为空，则所查元素不存在
	{
		cout<<"查找失败"<<endl;
		return -1;
	}
	else
		if(HT.elem[index]==key)
		{
			cout<<"查找成功！";
			cout<<"在第"<<index<<"个单元"<<endl;
			return index;  //若单元index中元素的关键字为key，则查找成功
		}
		else
		{
			for(i=1;i<m;++i)
			{
				index=Hash(Hash(key)+i);    //按照线性探测法计算下一个散列地址Hi
				if(HT.elem[index]==NULLKEY)//若单元index为空，则所查元素不存在
				{
					cout<<"查找失败"<<endl;
					return -1;
				}
				else
					if(HT.elem[index]==key)//查找成功
					{
						cout<<"查找成功！";
						cout<<"在第"<<index<<"个单元"<<endl;
						return index;  
					}
			}
			cout<<"查找失败"<<endl;
			return -1;
			
		}
}



int main()
{
	int key,num,i;
	HashTable HT;
	InitHashTable(HT);

	cout<<"请输入数据个数：";
	cin>>HT.count;

	//建立hash表
	cout<<"请输入"<<HT.count<<"个数据：";
	for(i=0;i<HT.count;i++)
	{
		cin>>num;
		InsertHash(HT,num);
	}

	//输出hash表
	cout<<"地址 关键字";
	cout<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"  "<<i<<"   "<<HT.elem[i];
		cout<<endl;
	}

	//查找
	while(1)
	{
	cout<<"请输入要查找的数:";
	cin>>key;
	SearchHash(HT,key);
	
	}
	return 1;
}