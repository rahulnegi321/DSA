class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1){
            return 1;
        }
        int count = 1;
        if(k%2 == 0 || k%5 == 0){
            return -1;
        }
        int num = 1; 
        while(1){
           if((num)%k == 0){
            return count;
           }
           else{
            num = (num*10+1)%k;
            count++;
           }
        }
        return -1;
    }
};