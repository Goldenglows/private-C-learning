#include <iostream>
using namespace std;

int main(){
    int arr[10];
    int height1,height2;
    int flag;

    for (int i=0;i<10;i++){
        cin>>arr[i];
        if(arr[i]<100 || arr[i]>200)
        {
            return -1;
        }
    }

    cin>>height1;

    if(height1<100 || height1>120)
    return -1;

    height2=height1+30;

    for(int j =0; j<10 ; j++){
        if(height2>=arr[j])
        flag++;
    }

    cout<<flag;

}
