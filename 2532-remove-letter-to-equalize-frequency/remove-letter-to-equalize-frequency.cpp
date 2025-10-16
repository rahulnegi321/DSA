class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int>mpp;
        for(int i = 0;i<word.size();i++){
            mpp[word[i]]++;
        }
        for(int i = 0;i<word.size();i++){
            mpp[word[i]]--;
            if(mpp[word[i]] == 0){
                mpp.erase(word[i]);
            }
            int temp =0;
            if(i+1 < word.size()){
                temp = mpp[word[i+1]];
            }
            else{
                temp = mpp[word[i-1]];
            }
            bool ans = true;
            for(auto it : mpp){
                if(it.second != temp){
                    ans = false;
                    break;
                }
            }
            if(ans == true){
                return true;
            }
            mpp[word[i]]++;
        }
       return false;
    }
};