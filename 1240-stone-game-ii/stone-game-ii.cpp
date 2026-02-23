class Solution {
public:
    map<tuple<int,int,bool>,int> dp;

    int helper(int ind, vector<int>& piles, bool a, int m){
        if(ind >= piles.size()){
            return 0;
        }

        auto it = make_tuple(ind,m,a);
        if(dp.count(it)){
            return dp[it];
        }

        int maxi = a ? INT_MIN : INT_MAX;
        int sum = 0;

        for(int i = ind; i < ind + 2*m && i < piles.size(); i++){
            sum += piles[i];

            int X = i - ind + 1;

            if(a){
                maxi = max(maxi,
                           sum + helper(i+1, piles, false, max(m,X)));
            }
            else{
                maxi = min(maxi,
                           helper(i+1, piles, true, max(m,X)));
            }
        }

        return dp[it] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        return helper(0, piles, true, 1);
    }
};