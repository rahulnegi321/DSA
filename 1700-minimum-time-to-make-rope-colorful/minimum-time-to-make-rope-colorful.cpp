class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;
        int i = 0;
        int n = colors.size();
        while(i+1 < n){
            if(colors[i] == colors[i+1]){
                count = count + min(neededTime[i],neededTime[i+1]);
                neededTime[i+1] = max(neededTime[i],neededTime[i+1]);
                i++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};