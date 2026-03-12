class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0){
            return 0;
        }
        vector<int>nums;
        int zero = 0;
        bool pos = true;
        if(num < 0){
           pos = false;
           num = abs(num);
        }
        while(num){
            int temp = num%10;
            if(temp == 0){
                zero++;
            }
            else{
                nums.push_back(temp);
            }
            num /= 10;
        }
        sort(nums.begin(),nums.end());
        long long ans = 0;
        if(pos == true){
          for(int i = 0;i<nums.size();i++){
             ans = ans*10 + nums[i];
             if(i == 0){
                ans = ans*(pow(10,zero));
             }
          }
        }
        else{
            int n = nums.size();
            for(int i = n-1;i>=0;i--){
                ans = ans*10 + nums[i];
            }
            ans = ans*pow(10,zero);
            return -ans;
        }
        return ans;
    }
};