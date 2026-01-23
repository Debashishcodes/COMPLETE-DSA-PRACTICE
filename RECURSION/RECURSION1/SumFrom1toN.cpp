//USING (PAREMETERIZED)
#include<iostream>
using namespace std;
void sum1toN(int sum,int n){
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    sum1toN(sum+n,n-1);
}
int main(){
    sum1toN(0,4);
}
// ANOTHER TRICK(USING RETURN TYPE)
#include<iostream>
using namespace std;
int sumupto(int n){
    if(n==1||n==0) return 1;
    return n+sumupto(n-1);
}
int main(){
    cout<<sumupto(5);
}