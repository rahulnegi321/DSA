class Solution {
public:
    bool isHappy(int n) {
      unordered_map<int,int>mpp;
      while(true){
         if(n == 1){
            return true;
        }
         if(mpp.count(n)){
            return false;
         }
         mpp[n]++;
         int temp = 0;
         while(n){
            temp += (n%10)*(n%10);
            n /= 10;
         }
         n = temp;
      }  
      return true;
    }
};