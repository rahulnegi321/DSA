class Solution {
public:
    map<int,int>mpp;
    int last = 0;
    bool isprime(int n){
        if(n < 2){
            return false;
        }
        if(n == 2 || n == 3 || n == 5){
            return true;
        } 
        if(n%2 == 0 || n%3 == 0 || n%5  ==0){
            return false;
        }
        for(int i = 5;i*i<=n;i+=6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }
        }
        return true;
    }
    int helper(int n){
        if(n == 1){
            return 0;
        }
        int ans = 0;
        for(int i = 2;i<=n;i++){
            if(isprime(i)){
                if(n%i == 0){
                    ans += i;
                    ans += helper(n/i);
                break;
                }
            }
        }
        return ans;
    }
    int smallestValue(int n) {
        int temp = helper(n);
        if(n == temp){
            return temp;
        }
        int ans = smallestValue(temp);
        return ans;
    }
};