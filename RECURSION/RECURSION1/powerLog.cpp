#include<iostream>
using namespace std;
int pow(int a , int b){
    if ( b == 1) return a;
    if(b%2==0){
    return pow(a,b/2)*pow(a,b/2);
    }
    if(b%2!=0){
    return pow(a,b/2)*pow(a,b/2)*a;
    }
}
int main(){
    int m;
    cout<<"enter base: ";
    cin>>m;
    int n;
    cout<<"enter exponent: ";
    cin>>n;
    cout<<m<<"raised to the power"<<n<<"is"<<pow(m,n); 
}