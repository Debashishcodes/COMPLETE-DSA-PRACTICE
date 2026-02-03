#include<iostream>
#include<vector>
using namespace std;
    bool check(long long mid,vector<int>& time, int totalTrips){
        long long trips = 0;
        int n = time.size();
        for(int i=0;i<=n-1;i++){
           trips+=mid/(long long)time[i];
        }
        if(trips<(long long)totalTrips) return false;
        else return true;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int mx = -1;
        for(int i=0;i<=n-1;i++){
            mx=max(mx,time[i]);
        }
        long long low=1;
        long long high=(long long )mx*(long long)totalTrips;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid,time,totalTrips)==true){
                ans = mid ;
                high = mid - 1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int main(){
        int n,totalTrips;
        cin>>n>>totalTrips;
        vector<int> time(n);
        for(int i=0;i<n;i++){
            cin>>time[i];
        }
        cout<<minimumTime(time,totalTrips)<<endl;
        return 0;
    }