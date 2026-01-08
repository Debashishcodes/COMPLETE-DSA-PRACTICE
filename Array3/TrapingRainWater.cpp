#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>&height){
    int n = height.size();
    int ans = 0;
    int l = 0;
    int r = n-1;
    int lmax = 0 ,rmax = 0;
    while(l<r){
        lmax= max (lmax,height[l]);
        rmax= max (rmax,height[r]);
        if(lmax<rmax){
            ans = ans + lmax - height[l];
            l++;
        }
        else{
            ans+= rmax - height[r];
            r--;
        }
    }
    return ans;
}
    int main(){
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(v);
    cout << "Trapped Water: " << result << endl;
    return 0;
}