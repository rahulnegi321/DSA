class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool one = false;
        bool two = false;
        bool three = false;
        for(auto it : triplets){
            int first = it[0];
            int second = it[1];
            int third = it[2];
            if(first == target[0] && second <= target[1] && third <= target[2]){
                one = true;
            }
            if(first <= target[0] && second == target[1] && third <= target[2]){
                two = true;
            }
            if(first <= target[0] && second <= target[1] && third == target[2]){
                three = true;
            }
            }
            return (one && two && three);
    }
};