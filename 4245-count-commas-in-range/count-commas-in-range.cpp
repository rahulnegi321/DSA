class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n < 1000){
            return 0;
        }
        long long temp = 1000;
        int coma = 1;
        while(temp <= n){
           // string t1 = to_string(temp);
           // string t2 = to_string(n);
            if(temp*1000 - 1 <= n){
                ans += coma*(temp*1000 -1 - temp+1);
            }else{
                ans += coma*(n-temp+1);
            }
            coma++;
            temp *= 1000;
        }
        return ans;
    }
};