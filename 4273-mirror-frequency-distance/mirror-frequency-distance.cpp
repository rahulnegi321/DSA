class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>mpp;
        unordered_map<char,int>counted;
        for(int i = 0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(counted.count(s[i])){
                continue;
            }
            char temp;
           if(isdigit(s[i])){
             temp = ('0'+('9'-s[i]));
           }
           else{
            temp = 'a' + ('z'-s[i]);
           }
        
           ans += abs(mpp[temp]-mpp[s[i]]);
           counted[s[i]]++;
           counted[temp]++;
        }
        return ans;
    }
};