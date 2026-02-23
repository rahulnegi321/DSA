class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int>mpp;
        if(s.size() < k){
            return false;
        }
        for(int i = 0;i<s.size()-k+1;i++){
            string temp = s.substr(i,k);
            mpp[temp]++;
        }
        if(mpp.size() == pow(2,k)){
            return true;
        }
        return false;
    }
};