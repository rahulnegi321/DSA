class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,vector<string>>mpp;
        for(int i = 0;i<code.size();i++){
            bool dikkat = false;
            if(code[i].size() == 0){
                continue;
            }
            for(int j =0;j<code[i].size();j++){
                if(!(code[i][j] == '_' || (code[i][j] >= 97 && code[i][j] <= 123) || (code[i][j] >= 65 && code[i][j] <= 91) || (code[i][j] >= '0' && code[i][j] <= '9'))){
                   dikkat = true;
                   break;
                }
            }
            if(dikkat){
                continue;
            }
            if(isActive[i] == true){
                mpp[businessLine[i]].push_back(code[i]); 
            }
        }
        vector<string>ans;
        if(mpp["electronics"].size() != 0){
            vector<string>temp = mpp["electronics"];
            sort(temp.begin(),temp.end());
            for(auto it : temp){
                ans.push_back(it);
            }
        }
        if(mpp["grocery"].size() != 0){
            vector<string>temp = mpp["grocery"];
            sort(temp.begin(),temp.end());
            for(auto it : temp){
                ans.push_back(it);
            }
        }
        if(mpp["pharmacy"].size() != 0){
            vector<string>temp = mpp["pharmacy"];
            sort(temp.begin(),temp.end());
            for(auto it : temp){
                ans.push_back(it);
            }
        }
        if(mpp["restaurant"].size() != 0){
            vector<string>temp = mpp["restaurant"];
            sort(temp.begin(),temp.end());
            for(auto it : temp){
                ans.push_back(it);
            }
        }
        return ans;
    }
};