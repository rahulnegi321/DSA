class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
        return false;
        }
     return !(n & n-1);   
    }
    int smallestNumber(int n) {
        int len = floor(log2(n))+1;
        int ans  = 0;
        for(int i = 0;i<len;i++){
          ans = ans + pow(2,i);
        }
        return ans;
    }
};