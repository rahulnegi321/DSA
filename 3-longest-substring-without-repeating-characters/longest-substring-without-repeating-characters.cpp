class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        unordered_set<char>mpp;
        int count = 1;
        int left = 0;
        for(int right = 0;right<n;right++){
           while(mpp.count(s[right])){
             mpp.erase(s[left]);
             left++;
           }
           mpp.insert(s[right]);
           count = max(count,right-left+1);
        }
        return count;
    }
};