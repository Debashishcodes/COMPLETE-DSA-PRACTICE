#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>ans(k);  //k elements ko insert karunga

        //CASE-1
        if(x<arr[0]){
           for(int i=0;i<k;i++){
            ans[i]=arr[i];
           } 
           return ans;
        }

        //CASE-2 ARR=1 2 3 4 5 , X = 4 , K = 3    0 0 0 -> 3 4 5 
        if(x>arr[n-1]){
            int i=n-1;
            int j = k-1; //3-1=2
            while(j>=0){
                ans[j]=arr[i];
                j--;
                i--;
            }
            return ans;
        }

        //CASE-3 
        int low = 0 ;
        int high = n-1;
        int mid = -1;
        bool flag = false; // if x is present in arr or not
        int t = 0; // representing index of ans 
        while(low<=high){
            mid = low + (high-low)/2;
            if(arr[mid]==x){
                flag = true ; //present
                ans[t]=arr[mid];
                t++;
                break;
            }
            else if (arr[mid]>x) high = mid -1 ;
            else low = mid + 1;
        }
        //CASE-3
        int lb = high ;
        int ub = low ;
        if(flag == true){
            lb = mid-1 ;
            ub = mid+1;
        }
        while( t<k &&  lb >=0 && ub<=n-1 ){
            int d1 = abs(x-arr[lb]);
            int d2 = abs(x-arr[ub]);
            if(d1<=d2){
                ans[t]=arr[lb];
                lb--;
            }
            else{    // d2<d1
                ans[t]=arr[ub];
                ub++;
            }
            t++;
        }
        if(lb<0){
            while(t<k){
              ans[t]=arr[ub];
              ub++;
              t++;  
            }
        }
        if(ub>n-1){
            while(t<k){
              ans[t]=arr[lb];
              lb--;
              t++;  
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
int main(){
    vector<int>arr={1,2,3,4,5}; 
    int k = 4;
    int x = -1; 
    vector<int>ans = findClosestElements(arr,k,x);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }  
    return 0;
}