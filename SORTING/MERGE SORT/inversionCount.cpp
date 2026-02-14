#include <iostream>
#include <vector>
using namespace std;
int c =0;
int inversion(vector<int>& a, vector<int>& b){
    int count =0;
    int i=0;
    int j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else { //a[i]<=b[j]
            i++;
        }    
    }
    return count;
}
void mergeVectors(vector<int>& v1, vector<int>& v2, vector<int>& v3){
    int n = v1.size();
    int m = v2.size();

    int i = 0, j = 0, k = 0;

    while(i < n && j < m){
        if(v1[i] < v2[j]){
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }
    while(i < n) v3[k++] = v1[i++];
    while(j < m) v3[k++] = v2[j++];
}
void mergesort(vector<int>& v){
    int n = v.size();
    if(n <= 1) return;

    int n1 = n/2;
    int n2= n-n/2;

    vector<int> a(n1);
    vector<int> b(n2);

    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int i=0; i<n2; i++) b[i] = v[i + n1];
    //doing recursion
    mergesort(a); 
    mergesort(b); 
    //count the inversion 
    c+=inversion(a,b);
    mergeVectors(a, b, v);
}

int main(){

    int arr[] = {5, 1, 3, 0, 4, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]); //7
    vector<int> v(arr, arr + n);  // same as array, copy

    cout << "Before sort: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout << endl;

    mergesort(v);

    // cout << "After sort : ";
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    cout<<c;
}
