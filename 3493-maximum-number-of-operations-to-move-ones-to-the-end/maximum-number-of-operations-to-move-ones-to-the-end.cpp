class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int ans  = 0;
        int n = s.size();
        int i = 0;
        while(i < n){
            while(s[i] == '1'){
                i++;
                count++;
            }
            if(i == n){
                break;
            }
            while(s[i] == '0'){
                i++;
            }
            ans = ans + count;
        }
        return ans;
    }
};