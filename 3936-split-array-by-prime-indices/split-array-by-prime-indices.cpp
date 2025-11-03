class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    if (n == 2) {
        return true;
    }
    
    if (n % 2 == 0) {
        return false;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
    long long splitArray(vector<int>& nums) {
        vector<int>primewale;
        vector<int>normal;
        for(int i = 0;i<nums.size();i++){
            if(isPrime(i)){
                primewale.push_back(nums[i]);
            }
            else{
                normal.push_back(nums[i]);
            }
        }
        long long sum1 = 0;
        long long sum2 = 0;
        if(primewale.size() == 0){
          sum1 = 0;
        }
        else{
            for(int i = 0;i<primewale.size();i++){
                sum1 = sum1 + primewale[i];
            }
        }
        for(int i = 0;i<normal.size();i++){
                sum2 = sum2 + normal[i];
            }
        return abs(sum1 - sum2);
    }
};