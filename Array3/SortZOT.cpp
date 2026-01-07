#include<iostream>
#include<vector>
using namespace std;
void sortcolors(vector<int>&nums){
    
    //one pass solution
    int low = 0;
    int mid= 0;
    int hi = nums.size()-1;

    while(mid<=hi){
        if(nums[mid]==2){
            int temp = nums[mid];
            nums[mid] = nums[hi];
            nums[hi] =  temp;
            mid++;
            hi--;
        }
        else if(nums[mid]==0){
            int temp = nums[mid];
            nums[mid]= nums[low];
            nums[low]= temp;
            low++;
            mid++;
        }
        else mid++;
    }
}
int main(){
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    sortcolors(v);

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
}