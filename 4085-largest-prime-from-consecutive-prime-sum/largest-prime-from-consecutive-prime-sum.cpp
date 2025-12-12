class Solution {
public:
    bool isPrime(int n){
        if(n == 2 || n == 3 || n == 5){
            return true;
        }
        if(n<2){
            return false;
        }
        if(n%2 == 0){
            return false;
        }
        if(n%3 == 0){
            return false;
        }
        for(int i = 5;i*i<=n;i=i+6){
            if(n%i == 0 || n %(i+2) == 0){
                return false;
            }
        }
        return true;
    }
    int largestPrime(int n) {
        if(n < 2){
            return 0;
        }
    long long sum = 0;
    int ans = 0;
    int i = 2;
    while(sum < n){
        if(isPrime(i)){
            sum = sum + i;
        }
        if(isPrime(sum) && sum <= n){
            ans = sum;
        }
        if(sum >= n){
            return ans;
        }
        i++;
    }  
    return 0;
    }
};