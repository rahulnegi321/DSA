class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mpp;
        for(auto it : hand){
            mpp[it]++;
        }
        sort(hand.begin(),hand.end());
        if(hand.size()%groupSize != 0){
            return false;
        }
        for(int i = 0;i<hand.size();i++){
            if(mpp[hand[i]] == 0){
                continue;
            }
            for(int j = hand[i];j<hand[i]+groupSize;j++){
                if(mpp[j] == 0){
                    return false;
                }
                else{
                    mpp[j]--;
                }
            }
        }
        return true;
    }
};