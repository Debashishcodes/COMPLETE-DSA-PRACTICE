#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string n;
    getline(cin,n);
    cout<<n<<endl;
    int len = n.length();
    reverse(n.begin(), n.begin() + len / 2);
    cout<<n;

}