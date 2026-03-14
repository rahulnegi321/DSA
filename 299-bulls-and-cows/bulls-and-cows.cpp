class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int countb = 0;
        int countc = 0;
        unordered_map<char,int>mpp;
        for(int i = 0;i<secret.size();i++){
            mpp[secret[i]]++;
        }
        for(int i = 0;i<guess.size();i++){
            if(guess[i] == secret[i]){
                countb++;
                mpp[secret[i]]--;
            }
        }
        for(int i = 0;i<guess.size();i++){
            if(guess[i] == secret[i]){
                continue;
            }
            if(mpp[guess[i]] != 0){
                countc++;
                mpp[guess[i]]--;
            }
        }
        ans += to_string(countb);
        ans += "A";
        ans += to_string(countc);
        ans += "B";
        return ans;
    }
};