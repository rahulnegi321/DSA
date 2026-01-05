class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int>mpp;
        int curr = 0;
        sort(trips.begin(),trips.end(),[](const vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        for(int i = 0;i<trips.size();i++){
            int start = trips[i][1];
            while(!q.empty() && q.top().first <= start){
                curr -= q.top().second;
                q.pop();
            }
            curr += trips[i][0];
            if(curr > capacity){
                return false;
            }
            q.push({trips[i][2],trips[i][0]});
        }
        return true;
    }
};