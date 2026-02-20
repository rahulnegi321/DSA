class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n  = nums.size();
        int count1 = 0;
        int count2 = 0;
        int one = 0;
        int two = 0;
        for(auto num : nums){
            if(num == one){
                count1++;
            }
            else if(num == two){
                count2++;
            }
            else if(count1 == 0){
                one = num;
                count1++;
            }
            else if(count2 == 0){
                two = num;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto num : nums){
            if(num == one){
                count1++;
            }
            else if(num == two){
                count2++;
            }
        }
        vector<int>res;
        if(count1 > n/3){
            res.push_back(one);
        }
        if(count2 > n/3){
            res.push_back(two);
        }
        return res;
    }
};