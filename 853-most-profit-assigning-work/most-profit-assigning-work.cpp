class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>temp;
        int n = profit.size();
        for(int i = 0;i<n;i++){
            temp.push_back({difficulty[i],profit[i]});
        }
        sort(temp.begin(),temp.end());
        int maxi = 0;
        unordered_map<int,int>mpp;

        for(int i = 0;i<n;i++){
           if(temp[i].second <= maxi){
              mpp[i]++;
              continue;
           }
           maxi = max(maxi,temp[i].second);
        }
        vector<int>diff;
        vector<int>pro;
        for(int i = 0;i<n;i++){
            if(mpp[i] == 0){
                diff.push_back(temp[i].first);
                pro.push_back(temp[i].second);
            }
        }
        int ans = 0;
        for(int i = 0;i<worker.size();i++){
            auto it = lower_bound(diff.begin(),diff.end(),worker[i]+1);
            if(it == diff.begin()){
                continue;
            }
            int ind = it-diff.begin();
            ind--;
            ans += pro[ind];
        }
        return ans;
    }
};