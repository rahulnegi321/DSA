class Solution {
public:
    int myAtoi(string s) {
       int count = 0;
       bool neg = false;
       int n= s.size();
       int start = 0;
       while(start < n){
        if(s[start] == ' '){
            start++;
        }
        else{
            break;
        }
       }
       if(start == n){
        return 0;
       }
       if(n == 0){
         return 0;
       }
       if(s[start] == '-'){
         neg = true;
         start++;
       }
       else if(s[start] == '+'){
        neg = false;
        start++;
       }
       if(n == 1){
         if(s[0] >= '0' && s[0] <= '9'){
            return s[0]-'0';
         }
         return 0;
       }
       long long ans = 0;
       for(int i = start;i<n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            ans += (s[i]-'0');
            long long temp = INT_MAX;
            temp++;
            if(ans > INT_MAX || (neg && (ans > temp))){
                if(neg){
                    return INT_MIN;
                }
                return INT_MAX;
            }
            count = ans;
        }
        else{
            break;
        }
       }
       return neg ? -(count) : count;
    }
};