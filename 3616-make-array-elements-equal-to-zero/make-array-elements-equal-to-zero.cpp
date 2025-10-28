class Solution {
public:
    int valid(vector<int>nums,int j){
        int n = nums.size();
        int i = j; 
        bool left = true;
        vector<int>temp = nums;
        int count = 0;
        while(i >= 0 && i < n){
            if(nums[i] > 0){
                nums[i]--;
                left = !left;
            }
            if(left){
                i++;
            }
            else{
                i--;
            }
        }
        int left1 = accumulate(nums.begin(),nums.end(),0);
        if(left1 == 0){
            count++;
        }
        i = j;
        left = false;
        while(i >= 0 && i < n){
            if(temp[i] > 0){
                temp[i]--;
                left = !left;
            }
            if(left){
                i++;
            }
            else{
                i--;
            }
        }
        int right1 = accumulate(temp.begin(),temp.end(),0);
        if(right1 == 0){
            count++;
        }
        return count;
    }
    int countValidSelections(vector<int>& nums) {
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0){
                count = count + valid(nums,i);
            }
        }
        return count;
    }
};