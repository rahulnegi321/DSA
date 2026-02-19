class Solution {
public:
    int countBinarySubstrings(string s) {
        int one = 0;
        int zero = 0;
        int ans = 0;
        int n = s.size();
        if(n == 1){
            return 0;
        }
        if(s[0] == '0'){
            zero++;
        }
        else{
            one++;
        }
        for(int i = 1;i<n;i++){
            if(s[i] != s[i-1]){
                if(s[i] == '0'){
                    zero = 0;
                }
                else{
                    one = 0;
                }
            }
            if(s[i] == '0'){
                zero++;
                if(one >= zero){
                    ans++;
                }
            }
            else{
                one++;
                if(zero >= one){
                    ans++;
                }
            }
        }
        return ans;
    }
};