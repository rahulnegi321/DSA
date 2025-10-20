class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count = 0;
        for(auto it : operations){
            if(it[0] == '+' || it[2] == '+'){
                count++;
            }
            else{
                count--;
            }
        }
        return count;
    }
};