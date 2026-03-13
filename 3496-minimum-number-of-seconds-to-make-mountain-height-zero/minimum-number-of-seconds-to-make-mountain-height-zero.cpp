class Solution {
public: 
    bool helper(int height,vector<int>&worker,long long time){
       for(int i = 0;i<worker.size();i++){
          long long curr = worker[i];
          int count = 2;
          while(curr <= time && height){
            height--;
           curr= curr + worker[i]*1LL*count;
           count++;
          }
          if(height == 0){
            break;
          }
       }
       if(height == 0){
        return true;
       }
       return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = LLONG_MAX;
        long long ans = LLONG_MAX;
        int height = mountainHeight;
        while(low <= high){
           long long mid = low + (high-low)/2;
           if(helper(height,workerTimes,mid)){
            ans = mid;
            high = mid-1;
           }
           else{
            low = mid+1;
           }
        }
        return ans;
    }
};