class Solution {
public:
    int integerBreak(int n) {
      if(n <= 3){
         return n-1;
      }
      if(n == 4){
        return 4;
      }
      int count = n/3;
      int remain = n%3;
      int temp = 1;
      if(remain == 1){
        count--;
        temp = 3+remain;
      }
      if(remain == 0){
        remain = 1;
      }
      return pow(3,count)*remain*temp;
    }
};