class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int maxi =0;
        int n= tokens.size();
        int l = 0;
        int r = n-1;
        while(l <= r){
            if(power >= tokens[l]){
                power = power - tokens[l];
                score++;
                l++;
                maxi = max(score,maxi);
            }
            else if(score > 0 && tokens[r] > power){
                score--;
                power = power + tokens[r];
                r--;
            }
            else{
                break;
            }
        }
        return maxi;
    }
};