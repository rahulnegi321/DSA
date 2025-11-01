class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>temp;
        for(auto mat : matrix){
            for(auto it : mat){
                temp.push_back(it);
            }
        }
        sort(temp.begin(),temp.end());
        return temp[k-1];
    }
};