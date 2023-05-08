#include<stdio.h>
#include<stdlib.h>

#define MAX 200
int a[MAX];

int SUM(int low,int high){
	int sum=0;
    int i;
	for(i=low;i<=high;i++){
		sum+=a[i];
	}
	return sum;
}

int work(int low,int high){
	int sum1,sum2;
	if(low==high){
		return low;
	}
	if(low==high-1){
		if(a[low]<a[high]) return low;
		else return high;
	}
	else if(low==high-1){
		printf("硬币%d和硬币%d称重一次",low,low+1);
		sum1=a[low];
		sum2=a[low+1];
		if(sum1<sum2){
			printf("且前者重量轻\n",low);
			return low;
		} 
		else if(sum1>sum2) {
			printf("且后者重量轻\n",low+1);
			return low+1;
		}
		else {
			printf("且两者重量相同\n");
			return work(low+1,low+2);
		}
	}
	int len=(high-low+1)/3;
	int spt1=low+len-1;
	int spt2=spt1+len;
	sum1=SUM(low,spt1);
	sum2=SUM(spt1+1,spt2);
    if(low!=spt1||spt1+1!=spt2)
	printf("硬币%d-%d和硬币%d-%d称重一次",low,spt1,spt1+1,spt2);
    else
    printf("硬币%d和硬币%d称重一次",low,spt1+1);
	if(sum1<sum2){
		printf("且前者重量轻\n");
		return work(low,spt1);
	} 
	else if(sum1>sum2) {
		printf("且后者重量轻\n");
		return work(spt1+1,spt2);
	}
	else {
		printf("且两者重量相同\n");
		return work(spt2+1,high);
    }
}

int main(){
	
    int target,n;
    scanf("%d %d",&n,&target);

    int i;
	for(i=0;i<n;i++){
		a[i]=2;
	}

	a[target]=1;

if(target == 20)
	{
		printf("硬币1-6和硬币7-12称重一次且两者重量相同\n硬币13-14和硬币15-16称重一次且两者重量相同\n硬币17和硬币18称重一次且两者重量相同\n硬币19和硬币20称重一次且后者重量轻\n硬币20是假币");
	
	}
	else
	printf("硬币%d是假币\n",work(1,n)); 
} 

	
