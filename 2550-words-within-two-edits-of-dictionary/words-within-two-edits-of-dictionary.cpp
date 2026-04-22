class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        vector<string>words = queries;
        for(int i = 0;i<queries.size();i++){
            bool found = false;
            for(int j = 0;j<dictionary.size();j++){
                int count = 0;
                if(queries[i].size() != dictionary[j].size()){
                    continue;
                }
                for(int k = 0;k<words[i].size();k++){
                    if(words[i][k] != dictionary[j][k]){
                        count++;
                        if(count > 2){
                            break;
                        }
                    }
                }
                if(count <= 2){
                    found = true;
                    break;
                }
            }
            if(found){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};