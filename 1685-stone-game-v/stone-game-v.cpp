class Solution {
public:
    vector<int>presum;
    int helper(int ind,int idx,vector<int>&stone,vector<vector<int>>&dp){
        
       if(ind >= idx){
        return 0;
       }
       if(dp[ind][idx] != -1){
        return dp[ind][idx];
       }
       double sum = presum[idx] - presum[ind] + stone[ind];
       int curr = 0;
       double temp = (double)sum/2.00;
       int ans = 0;
    //    for(int i = ind;i<=idx;i++){
    //      if(curr + stone[i] > temp){
    //         ans =  curr + helper(ind,i,stone,dp);
    //         break;
    //      }
    //      else if(curr + stone[i] == temp){
    //         curr += stone[i];
    //         ans = curr + max(helper(ind,i,stone,dp),helper(i+1,idx,stone,dp));
    //         break;
    //      }
    //      curr += stone[i];
    //    }
    int i = ind;
    while(curr <= temp){
        curr += stone[i];
        if(curr > temp){
            break;
        }
        ans = max(ans,curr+helper(ind,i,stone,dp));
        i++;
    }
    i = idx;
    curr = 0;
    while(curr <= temp){
       curr += stone[i];
       if(curr > temp){
        break;
       }

       ans = max(ans,curr+helper(i,idx,stone,dp));
       i--;
    }
    //    curr = 0;
    //    for(int i = idx;i>=ind;i--){
    //      if(curr + stone[i] > temp){
    //         ans = max(ans,helper(i+1,idx,stone,dp));
    //      }
    //      else if(curr + stone[i] == temp){
    //         break;
    //      }
    //      curr += stone[i];
    //    }
       return dp[ind][idx] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int sum = 0;
        int n = stoneValue.size();
        if(n == 2){
            return min(stoneValue[0],stoneValue[1]);
        }
        for(int i = 0;i<stoneValue.size();i++){
            sum += stoneValue[i];
            presum.push_back(sum);
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,stoneValue,dp);
    }
};