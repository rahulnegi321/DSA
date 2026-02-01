class Solution {
public:
    int countMonobit(int n) {
        int count = 1;
       for(int i = 1;i<=n;i++){
        if(i%2 == 0){
            continue;
        }
         int temp = __builtin_popcount(i);
         int temp1 = (1 + log2(i));
         if(temp == temp1){
            count++;
         }
       }
       return count;
    }
};