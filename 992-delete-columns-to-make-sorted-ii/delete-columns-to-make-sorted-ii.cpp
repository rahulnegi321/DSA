class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        if(strs.size() == 1){
            return 0;
        }
         unordered_map<int,int>mpp;
        for(int i = 0;i<strs[0].size();i++){
            bool found = false;
            bool same = false;
            vector<int>temp;
            for(int j = 1;j<strs.size();j++){
                if(mpp[j] > 0){
                    continue;
                }
               if(strs[j][i] < strs[j-1][i]){
                 count++;
                 found = true;
                 break;
               }
               else if(strs[j][i] == strs[j-1][i]){
                same = true;
               }
               else{
                temp.push_back(j);
               }
            }
            if(found == false){
                for(auto it : temp){
                    mpp[it]++;
                }
            }
            if(found == false && same == false){
                break;
            }
        }
        return count;
    }
};