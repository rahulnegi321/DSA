class Solution {
public:
    unordered_map<int,int>mpp;
    bool helper(int n){
        bool find = false;
       while(n){
         if(!mpp.count(n%10)){
            return false;
         }
         if(n%10 == 2 || n%10 == 5 || n%10 == 6 || n%10 == 9){
            find = true;
         }
         n /= 10;
       }
       return find;
    }
    int rotatedDigits(int n) {
       mpp[0]++;
       mpp[1]++;
       mpp[8]++;
       mpp[2]++;
       mpp[5]++;
       mpp[6]++;
       mpp[9]++;
       int count = 0;
       for(int i = 1;i<=n;i++){
          if(helper(i)){
             count++;
          }
       }
       return count;
    }
};