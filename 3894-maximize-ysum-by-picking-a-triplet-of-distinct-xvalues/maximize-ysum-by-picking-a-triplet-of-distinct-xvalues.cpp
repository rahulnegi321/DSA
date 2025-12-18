class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        set<int>t(x.begin(),x.end());
        if(t.size() < 3){
          return -1;
        }
        unordered_map<int,int>mpp;
        for(int i =0;i<x.size();i++){
            int temp = mpp[x[i]];
            mpp[x[i]] = max(temp,y[i]);
        }
        priority_queue<int>q;
        for(auto it : mpp){
            q.push(-it.second);
            if(q.size() > 3){
              q.pop();
            }
        }
        int ans  = 0;
        while(!q.empty()){
          ans = ans + (-q.top());
          q.pop();
        }
        return ans;
    }
};