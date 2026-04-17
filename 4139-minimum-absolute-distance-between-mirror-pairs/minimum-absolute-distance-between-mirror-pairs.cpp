class Solution {
public:
    int reve(int n){
        string temp = to_string(n);
        reverse(temp.begin(),temp.end());
        int ans = stoi(temp);
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,vector<int>>mpp;
        int n = nums.size();
        for(int i = n-1;i>=0;i--){
           mpp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            mpp[nums[i]].pop_back();
            int rev = reve(nums[i]);
            if(!mpp.count(rev)){
                continue;
            }
            if(mpp[rev].empty()){
                continue;
            }
            int last = mpp[rev].back();
            ans = min(ans,last-i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};