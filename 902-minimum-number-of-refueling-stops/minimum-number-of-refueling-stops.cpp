class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>q;
        int curr = startFuel;
        int count = 0;
        for(int i = 0;i<stations.size();i++){
            int pos = stations[i][0];
            int fuel = stations[i][1];
            if(curr < pos){
                if(q.size() == 0){
                    return -1;
                }
                else{
                    while(q.size() && curr < pos){
                        curr = curr + q.top();
                        count++;
                        q.pop();
                    }
                }
            }
            if(curr < pos){
                return -1;
            }
            q.push(fuel);
        }
        while(curr < target && q.size()){
             curr += q.top();
             q.pop();
             count++;
        }
        if(curr < target){
            return -1;
        }
        return count;
    }
};