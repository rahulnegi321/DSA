class Solution {
public:
    int minFlips(string s) {
        string str = s+s;
        string st1 = "";
        string st2 = "";
        int n = s.size();
        for(int i = 0;i<2*n;i++){
            if(i%2 == 0){
                st1 += '1';
                st2 += '0';
            }
            else{
                st1 += '0';
                st2 += '1';
            }
        }
        int d1 = 0;
        int d2 = 0;

        int l = 0;
        int ans = INT_MAX;
        for(int r = 0;r<2*n;r++){
            if(st1[r] != str[r]){
                d1++;
            }
            if(st2[r] != str[r]){
                d2++;
            }
            if(r-l+1 > n){
                if(st1[l] != str[l]){
                    d1--;
                }
                if(st2[l] != str[l]){
                    d2--;
                }
                l++;
            }
            if(r-l+1 == n){
              ans = min({ans,d1,d2});
            }
        }
        return ans;
    } 
};