class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>mix;
        for(int i = 0;i<arr.size();i++){
            int temp = __builtin_popcount(arr[i]);
            mix.push_back({temp,arr[i]});
        }
        sort(mix.begin(),mix.end());
        vector<int>finalans;
        for(auto it : mix){
            finalans.push_back(it.second);
        }
        return finalans;
    }
};