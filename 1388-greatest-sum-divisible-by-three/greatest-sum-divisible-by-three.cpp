class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int>one;
        vector<int>two;
        for(int i =0;i<nums.size();i++){
            sum = sum + nums[i];
            if(nums[i]%3 == 1){
                one.push_back(nums[i]);
            }
            else if(nums[i]%3 == 2){
               two.push_back(nums[i]);
            }
        }
        if(sum % 3 == 0){
            return sum;
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(sum % 3  == 1){
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if(one.size()){
                op1 = one[0];
            }
            if(two.size() >= 2){
                op2 = two[0]+ two[1];
            }
            sum = sum - min(op1,op2);
        }
        else{
            int op1 = INT_MAX;
            int op2 = INT_MAX;
            if(two.size()){
                op1 = two[0];
            }
            if(one.size() >= 2){
                op2 = one[0]+ one[1];
            }
            sum = sum - min(op1,op2);
        }
        return max(0,sum);
    }
};