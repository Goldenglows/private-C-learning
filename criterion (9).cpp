#include<iostream>
using namespace std;

typedef int Status;


//ɢ�б�Ĳ���
//���ŵ�ַ��ɢ�б�Ĵ洢��ʾ
#define m 20 //ɢ�б�ı�
#define NULLKEY 0 //��ԪΪ�յı��
#define OK 1
#define OVERFLOW -1

typedef struct
{
	int *elem;//����Ԫ�ش洢��ַ����̬��������
	int count;//��ǰ����Ԫ�ظ���
}HashTable;


Status InitHashTable(HashTable &HT)
{//��ʼ��hash��
	int i;
	
	HT.elem=new int[m];//ɢ�б�ı�
	if(!HT.elem)
		exit(OVERFLOW);//�洢����ʧ��
	for(i=0;i<m;i++)
		HT.elem[i]=NULLKEY;//��ԪΪ�յı��
	HT.count=0;//��ǰԪ�ظ���Ϊ0
	return OK;
}

int Hash(int key)
{//��ȡλ���±�
	return key%13;
}

//hash��Ľ���
void InsertHash(HashTable &HT,int key)
{
	int num=1;
	int index=Hash(key);//λ���±�

	while(HT.elem[index]!=NULLKEY)//������
	{
		index=Hash(Hash(key)+num);
		num++;
	}
	HT.elem[index]=key;
}

		


//ɢ�б�Ĳ���
int SearchHash(HashTable HT,int key)
{//��ɢ�б��в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ������ص�Ԫ��ţ����򷵻�-1
	int index;
	index=Hash(key);//����ɢ�к���H(key)����ɢ�е�ַ
	int i;
	if(HT.elem[index]==NULLKEY)//����ԪindexΪ�գ�������Ԫ�ز�����
	{
		cout<<"����ʧ��"<<endl;
		return -1;
	}
	else
		if(HT.elem[index]==key)
		{
			cout<<"���ҳɹ���";
			cout<<"�ڵ�"<<index<<"����Ԫ"<<endl;
			return index;  //����Ԫindex��Ԫ�صĹؼ���Ϊkey������ҳɹ�
		}
		else
		{
			for(i=1;i<m;++i)
			{
				index=Hash(Hash(key)+i);    //��������̽�ⷨ������һ��ɢ�е�ַHi
				if(HT.elem[index]==NULLKEY)//����ԪindexΪ�գ�������Ԫ�ز�����
				{
					cout<<"����ʧ��"<<endl;
					return -1;
				}
				else
					if(HT.elem[index]==key)//���ҳɹ�
					{
						cout<<"���ҳɹ���";
						cout<<"�ڵ�"<<index<<"����Ԫ"<<endl;
						return index;  
					}
			}
			cout<<"����ʧ��"<<endl;
			return -1;
			
		}
}



int main()
{
	int key,num,i;
	HashTable HT;
	InitHashTable(HT);

	cout<<"���������ݸ�����";
	cin>>HT.count;

	//����hash��
	cout<<"������"<<HT.count<<"�����ݣ�";
	for(i=0;i<HT.count;i++)
	{
		cin>>num;
		InsertHash(HT,num);
	}

	//���hash��
	cout<<"��ַ �ؼ���";
	cout<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"  "<<i<<"   "<<HT.elem[i];
		cout<<endl;
	}

	//����
	while(1)
	{
	cout<<"������Ҫ���ҵ���:";
	cin>>key;
	SearchHash(HT,key);
	
	}
	return 1;
}