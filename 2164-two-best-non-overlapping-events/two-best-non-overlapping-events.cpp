class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int,int>mpp;
        sort(events.begin(),events.end());
        int temp = 0;
        int value = 0;
        int n = events.size();
        for(int i = n-1;i>=0;i--){
           int start  = events[i][0];
           int end  = events[i][1];
           int curr = events[i][2];
           if(temp != start){
             mpp[temp] = value;
             temp = start;
             value = max(value,curr);
           }
           else{
              value = max(value,curr);
           }
        }
        priority_queue<int>q;
        for(auto it : events){
            q.push(it[2]);
        } 
        for(auto it : events){
           int ans = it[2];
           auto t = mpp.lower_bound(it[1]+1);
           if(t != mpp.end()){
            ans += t->second;
           }
           q.push(ans);
        }
        return q.top();
    }
};