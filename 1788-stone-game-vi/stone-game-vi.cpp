class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>>q;
        int n = aliceValues.size();
        for(int i = 0;i<n;i++){
            int curr = aliceValues[i] + bobValues[i];
            q.push({curr,i});
        }
        int ali = 0;
        int bob = 0;
        while(n){
           int temp = q.top().first;
           int ind = q.top().second;
           q.pop();
           ali += aliceValues[ind];
           n--;
           if(n == 0){
            break;
           }
           temp = q.top().first;
           ind = q.top().second;
           q.pop();
           bob += bobValues[ind];
           n--;
        }
        return ali > bob ? 1 : (ali < bob ? -1 : 0);
    }
};