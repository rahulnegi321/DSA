class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int>&a,vector<int>&b){
            if(a[1] != b[1]){
              return a[1] < b[1];
            }
            if(a[2] != b[2]){
              return a[2] < b[2];
            }
            return a[0] < b[0];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int curr = 0;
        for(int i = 0;i<trips.size();i++){
            while(q.size() && q.top().first <= trips[i][1]){
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