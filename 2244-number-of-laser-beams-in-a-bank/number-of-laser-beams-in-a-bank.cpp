class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int ans = 0;
        for(int i =0;i<bank.size();i++){
            int temp = 0;
            for(int j = 0;j<bank[i].size();j++){
                if(bank[i][j] == '1'){
                    temp++;
                }
            }
            if(temp == 0){
                continue;
            }
                ans = ans + count*temp;
                count = temp;
        }
        return ans;
    }
};