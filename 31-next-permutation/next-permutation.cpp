class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        
        for(int i = n-1;i>=0;i--){
            if(mpp.count(nums[i])){
                continue;
            }
            mpp[nums[i]] = i;
        }
        int temp = -1;
        for(int i = n-2;i>=0;i--){
           if(nums[i] < nums[i+1]){
            temp = i;
            break;
           }
        }
        if(temp == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int start = -1;
        int count = nums[temp]+1;
        while(1){
           if(mpp.count(count)){
             if(mpp[count] > temp){
                start = mpp[count];
                break;
             }
           }
           count++;
        }

        swap(nums[temp],nums[start]);
        sort(nums.begin()+temp+1,nums.end());
        return;
    }
};