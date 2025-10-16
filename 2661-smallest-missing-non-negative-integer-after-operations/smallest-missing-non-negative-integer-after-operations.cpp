class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int>temp(value,0);
        for(int i = 0;i<n;i++){
            int reminder = (nums[i]%value + value)%value;
            temp[reminder]++;
        }
        for(int i = 0;i<n;i++){
            int need = i%value;
            if(temp[need] == 0){
                return i;
            }
            temp[need]--;
        }
        return n;
    }
};