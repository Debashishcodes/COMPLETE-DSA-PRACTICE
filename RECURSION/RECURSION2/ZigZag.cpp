#include<iostream>
using namespace std;
void zig(int n){
    if(n==0) return;
    cout<<n;
    zig(n-1);
    cout<<n;
    zig(n-1);
    cout<<n;
}
int main(){
    cout<<endl;
    zig(3);
    cout<<endl;
}