class Solution {
public:
    int minimumDeletions(string s) {
        unordered_map<int,int>counta;
        unordered_map<int,int>countb;
        int a  = 0;
        int b = 0;
        int n = s.size();
        for(int i = n-1;i>=0;i--){
            counta[i] = a;
            if(s[i] == 'a'){
                a++;
            }
        }
        for(int i = 0;i<n;i++){
            countb[i] = b;
            if(s[i] == 'b'){
                b++;
            }
        }
        if(b == 0 || a == 0){
            return 0;
        }
        int ans = n;
        for(int i = 0;i<n;i++){
            ans = min(counta[i] + countb[i],ans);
        }
        return ans;
    }
};