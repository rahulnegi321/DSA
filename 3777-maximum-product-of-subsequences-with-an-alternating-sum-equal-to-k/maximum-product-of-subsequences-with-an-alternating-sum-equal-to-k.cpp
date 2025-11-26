class Solution {
    int n,k,lim;
    private:
        int helper(int ind,int sum,long long prod,int sign,int taken,vector<int>&nums,unordered_map<string,int>&mpp){
           if(ind >= nums.size()){
            if(taken && prod <= lim && sum == k){
                return prod;
            }
            return -1;
           }
           string key = to_string(ind) + to_string(sum) + to_string(prod) + to_string(sign) + to_string(taken);
           if(mpp.count(key)){
            return mpp[key];
           }
           int nottake = helper(ind+1,sum,prod,sign,taken,nums,mpp);
           int take = helper(ind+1,sign == 0?sum+nums[ind]:sum-nums[ind],prod*nums[ind] > lim ? lim+1 : prod*nums[ind],!sign,1,nums,mpp);
           return mpp[key] = max(take,nottake); 
        }
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        this->n = nums.size();
        this->k = k;
        this->lim = limit;
        int sum = 0;
        for(auto it: nums) sum += it;
        if(sum < abs(k)) return -1;
        unordered_map<string,int>mpp;
        return helper(0,0,1LL,0,0,nums,mpp);
    }
};

