class Solution {
public:
    int longestBalanced(string s) {
        int count  = 1;
        for(int i = 0;i<s.size();i++){
            unordered_map<char,int>mpp;
            for(int j = i;j<s.size();j++){
              mpp[s[j]]++;
              int temp = mpp[s[j]];
              bool check = true;
              for(auto it : mpp){
                if(it.second != temp){
                  check = false;
                }
              }
              if(check){
                count = max(count,j-i+1);
              }
            }
        }
        return count;
    }
};