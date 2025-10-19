class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int i = 1;
        while(1){
            int temp = k*i;
            if(!st.count(temp)){
                return temp;
            }
            i++;
        }
        return 0;
    }
};