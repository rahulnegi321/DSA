class Solution {
public:
    int bestClosingTime(string customers) {
        int besttime = 0;
        int mini = 0;
        int pre =0 ;
        for(int i =0;i<customers.size();i++){
            pre += customers[i] == 'Y' ? -1 : 1;

            if(pre < mini){
                besttime = i+1;
                mini = pre;
            }
        }
        return besttime;
    }
};