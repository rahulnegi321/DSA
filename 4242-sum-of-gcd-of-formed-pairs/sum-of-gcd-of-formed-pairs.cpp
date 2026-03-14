class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>gcds;

        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            int temp = gcd(nums[i],maxi);
            gcds.push_back(temp);
        }
        sort(gcds.begin(),gcds.end());
        int left = 0;
        int right = gcds.size()-1;
        long long sum = 0;
        while(left < right){
            int temp = gcd(gcds[left],gcds[right]);
            sum += temp;
            left++;
            right--;
        }
        
        return sum;
    }
};