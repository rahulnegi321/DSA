class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_l = 0;
        int count_r = 0;
        int neu = 0;
        for(int i = 0;i<moves.size();i++){
            if(moves[i] == 'L'){
                count_l++;
            }
            else if(moves[i] == 'R'){
                count_r++;
            }
            else{
                neu++;
            }
        }
        if(count_l > count_r){
            return count_l + neu - count_r;
        }
        return count_r + neu - count_l;
    }
};