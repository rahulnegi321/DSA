class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans;
        vector<pair<int,int>>next;
        unordered_map<int,int>mpp;
        for(int i = n-1;i>=0;i--){
            if(!mpp.count(rains[i])){
                mpp[rains[i]] = i;
                next.push_back({INT_MIN,rains[i]});
            }
            else{
                int temp = mpp[rains[i]];
                mpp[rains[i]] = temp;
                next.push_back({-temp,rains[i]});
            }
        }
        reverse(next.begin(),next.end());
        unordered_map<int,int>count;
        priority_queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            if(rains[i] == 0){
                if(q.empty()){
                    ans.push_back(1);
                }
                else{
                    int temp = q.top().second;
                    q.pop();
                    ans.push_back(temp);
                    count[temp]--;
                }
            }
            else{
               count[rains[i]]++;
               q.push(next[i]);
               ans.push_back(-1);
               if(count[rains[i]] > 1){
                return {};
               }
            }
        }
        return ans;
    }
};