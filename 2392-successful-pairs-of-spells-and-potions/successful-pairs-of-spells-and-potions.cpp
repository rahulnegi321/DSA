class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i = 0;i<spells.size();i++){
           long long temp = (success + spells[i] - 1) / spells[i];
           auto it = lower_bound(potions.begin(),potions.end(),temp);
           int dis = potions.end()-it;
           ans.push_back(dis);
        }
        return ans;
    }
};