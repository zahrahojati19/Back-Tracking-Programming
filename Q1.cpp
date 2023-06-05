#include <iostream>

using namespace std;

void passage(int arr[], int count , int pos, int x, int n){
    int y;
    if ((pos+x)>n) return;
    else if(count%2==0){
        if(count==0) y = max(arr[0],0);
        else y = max(arr[pos],arr[pos + x]);
        if (y==0) {cout<<0<<endl; return ;}  
    }
    else if(count%2 != 0){
        y = min(arr[pos], arr[pos + x]);
    }
    cout<< arr[pos + x] <<" ";
    pos=pos + x;
    count++;
    passage(arr, count, pos, y, n);
}
int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    passage(arr, 0 , 0, 0, n);
}