#include<stdio.h>
 void Binary_Search(int key,int a[],int n)
 {
 	int i,high,low,mid;
 	int count1=0,count=0;
 	low=0;
 	high=n-1;
 	while(high>=low)
 	{	
		count++;
		mid=(high+low)/2;
 		if(key<a[mid])
		high=mid-1;
 		else if(key>a[mid])
 		low=mid+1;
		if(key==a[mid])
		{
			printf("���ҳɹ���Ϊ��%d��Ԫ�أ�ֵΪ%d\n",mid,key);
			count1++;
			break;
		}
	}
	 if(count1==0)
	 printf("δ�ҵ�");
 }
 int main ()
 {
 	int n=10;
	int a[100]={7,10,13,16,19,29,32,33,37,41,43};
 	int key =33;
 	void Binary_Search(int key,int a[],int n);
 	//printf("������˳�����Ԫ�ظ�����\n");
 	//scanf("%d",&n);
 	//printf("���������б���Ԫ�أ�\n");
 	//for(int i=0;i<n;i++)
 	//{
 	//	scanf("%d",&a[i]);
	//}
	//printf("������Ҫ���ҵ�����\n");
	//scanf("%d",&key);
	 Binary_Search(key,a,n);
	 printf("\n");
	 return 0;
 }