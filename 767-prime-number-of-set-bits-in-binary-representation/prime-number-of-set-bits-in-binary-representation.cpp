class Solution {
public:
    bool isprime(int n){
        if(n < 2){
            return false;
        }
        if(n == 2 || n == 3 || n == 5){
            return true;
        }
        if(n <= 6){
            return false;
        }
        if(n%2 == 0 || n%3 == 0){
            return false;
        }
        for(int i = 5;i*i<=n;i+=6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        while(left <= right){
          int temp = __builtin_popcount(left);
          if(isprime(temp)){
            count++;
          }
          left++;
        }
        return count;
    }
};