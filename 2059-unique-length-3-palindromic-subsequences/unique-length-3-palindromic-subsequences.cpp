class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        int n = s.size();
        int counter = 0;
        unordered_map<char,pair<int,int>>mpp;
        for(int i = 0;i<s.size();i++){
            if(mpp.count(s[i])){
                int temp = mpp[s[i]].first;
                mpp[s[i]] = {temp,i};
            }
            else{
                mpp[s[i]] = {i,i};
            }
        }

        for(auto it : mpp){
           if(it.second.second - it.second.first <= 1){
                continue;
            }
            unordered_map<char,int>mpp2;
            for(int i = it.second.first+1;i<it.second.second;i++){
                mpp2[s[i]]++;
            }

            count = count + mpp2.size();
        }
        return count;
    }
};