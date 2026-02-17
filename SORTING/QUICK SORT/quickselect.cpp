#include<iostream>
#include<algorithm>
using namespace std;
int partition(int arr[],int startidx,int endidx){
    int pivotelement = arr[startidx]; //5
    int count = 0;
    for(int i = startidx+1;i<=endidx;i++){
        if(arr[i]<=pivotelement){
            count++;
        }
    }
    int pivotidx = count + startidx;
    swap(arr[startidx],arr[pivotidx]);
    int i = startidx;
    int j = endidx;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]<=pivotelement) i++;
        else if(arr[j]>pivotelement) j--;
        else if (arr[i]>pivotelement && arr[j]<pivotelement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}
int kthSmallest(int arr[],int startidx,int endidx,int k){
    int pivotindex = partition(arr,startidx,endidx); // pivotindex = 4
    if(pivotindex + 1==k) return arr[pivotindex];
    else if(pivotindex + 1 < k) return kthSmallest(arr,pivotindex+1,endidx,k);
    else return kthSmallest(arr,startidx,pivotindex-1,k);
    
}
int main(){
    int arr[]={5,18,82,20,7,6,31,4,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //quicksort(arr,0,n-1);
    cout<<endl;
    int k = 3;
    cout<<kthSmallest(arr,0,n-1,k);
    
}