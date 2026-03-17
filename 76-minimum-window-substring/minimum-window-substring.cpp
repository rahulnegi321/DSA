class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto c : t){
            mpp[c]++;
        }
        unordered_map<char,int>curr;
        int left = 0;
        int ans = INT_MAX;
        int n = s.size();
        int start = 0;
        int end = n;
        for(int i = 0;i<n;i++){
            curr[s[i]]++;
            bool pos = true;
            for(auto it : mpp){
                int temp = it.first;
                int count = it.second;
                if(curr[temp] < count){
                    pos = false;
                    break;
                }
            }
            if(pos){
                if(end-start+1 > i-left+1){
                    start = left;
                    end = i;
                }
            }
            while(pos){
                curr[s[left]]--;
                if(curr[s[left]] < mpp[s[left]]){
                    left++;
                    break;
                }
                left++;
                if(end-start+1 > i-left+1){
                    start = left;
                    end = i;
                }
            }
        }
        if(end == n){
            return "";
        }
        return s.substr(start,end-start+1);
    }
};