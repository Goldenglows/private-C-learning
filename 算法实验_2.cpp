#include <stdio.h>

int main(){
    int num1,num2;

    scanf("%d,%d",&num1,&num2);

    //判断输入的数字是否大于1
    if(num1>=1 && num2>=1){
        int i,j;
        int m=0;
        for( i = num1; i<=num2;i++){
            int flag=0;
            for( j=num1; j<i ;j++){
                if(i%j==0){
                    
                    flag += j;
                }
            }
            if ( i == flag){
            printf("%d\n",i);
            m++;
            }
            
        }
        printf("%d",m);
        return 0;

    }
    else{
        printf("输入错误");
        return -1;
    }


}