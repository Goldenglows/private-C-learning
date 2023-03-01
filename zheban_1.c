#include <stdio.h>
#include <stdlib.h>

//折半查找，二分查找，仅适用于有序的顺序表

typedef struct zheban_1
{
    /* data */
    ElemType *elem;
    int TableLen;
};

int binary_Search(struct zheban_1 L,ElemType key ){
    int low=0,high = L.TableLen -1,mid;
    //low在第0位，high 在表长度减一的位置
    while(low <= high){
        mid = (low+high)/2;
        //mid在low和high的中间
        if(L.elem[mid]==key)  
        //中间点恰好是要查找的位置
            return mid;
        else if(L.elem[mid]>key)
        //查找的若比中间数值小，下一次就要在中间的左侧查找
            high=mid-1;
        else    
        //若大，则要在中间右侧查找
            low=mid+1;

    }
}