class Solution {
public:
    vector<vector<int>>finalans;
    void helper(int curr,int k,int n,vector<int>&temp,vector<int>&ans){
        if(curr >= temp.size()){
            if(n == 0 && k == 0){
            finalans.push_back(ans);
            }
            return;
        }
        if(temp[curr] <= n){
            ans.push_back(temp[curr]);
            n -= temp[curr];
            k--;
            helper(curr+1,k,n,temp,ans);
            ans.pop_back();
            n += temp[curr];
            k++;
        }
        helper(curr+1,k,n,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        for(int i = 1;i<=9;i++){
            temp.push_back(i);
        }
        vector<int>ans;
        helper(0,k,n,temp,ans);
        if(finalans.size()==0){
            return {};
        }
        return finalans;
        vector<vector<int>>result(finalans.begin(),finalans.end());
        return result;
    }
};