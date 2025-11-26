class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int start = 2;
        while(1){
            if(n < pow(2,start)){
                return pow(2,start);
            }
            else{
                start++;
            }
        }
        return -1;
    }
};