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
			printf("查找成功，为第%d个元素，值为%d\n",mid,key);
			count1++;
			break;
		}
	}
	 if(count1==0)
	 printf("未找到");
 }
 int main ()
 {
 	int n=10;
	int a[100]={7,10,13,16,19,29,32,33,37,41,43};
 	int key =33;
 	void Binary_Search(int key,int a[],int n);
 	//printf("请输入顺序表中元素个数：\n");
 	//scanf("%d",&n);
 	//printf("请输入所有表中元素：\n");
 	//for(int i=0;i<n;i++)
 	//{
 	//	scanf("%d",&a[i]);
	//}
	//printf("请输入要查找的数：\n");
	//scanf("%d",&key);
	 Binary_Search(key,a,n);
	 printf("\n");
	 return 0;
 }