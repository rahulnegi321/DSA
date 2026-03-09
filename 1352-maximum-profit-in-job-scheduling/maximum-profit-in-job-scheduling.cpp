class Solution {
public:
    int dp[100000];
    int helper(vector<int>&start,vector<int>&end,vector<int>&pro,int ind){
        if(ind >= start.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }

        int end_time = end[ind];
        int ne = 0;
        auto next = lower_bound(start.begin(),start.end(),end_time);
        if(next == start.end()){
            ne = start.size();
        }
        else{
            ne = next-start.begin();
        }
        int take = pro[ind] + helper(start,end,pro,ne);
        int nottake = helper(start,end,pro,ind+1);
        return dp[ind] = max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>temp;
        int n = startTime.size();
        for(int i = 0;i<n;i++){
            temp.push_back({startTime[i],{profit[i],endTime[i]}});
        }
        sort(temp.begin(),temp.end());
        vector<int>start;
        vector<int>end;
        vector<int>pro;
        for(int i = 0;i<temp.size();i++){
            start.push_back(temp[i].first);
            end.push_back(temp[i].second.second);
            pro.push_back(temp[i].second.first);
        }
        memset(dp,-1,sizeof(dp));
        return helper(start,end,pro,0);
    }
};