class Solution {
public:
    bool helper(int n){
        unordered_map<int,int>mp;
        while(n != 0){
         mp[n%10]++;
         n = n/10;
        }
        for(auto it : mp){
            if(it.first != it.second){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if(n >= 666666) return 1224444;
        while(1){
            n = n + 1;
            if(helper(n)){
                return n;
            }
        }
        return -1;
    }
};