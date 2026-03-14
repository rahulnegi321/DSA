class Solution {
public:
    int count = 0;
    int maxi = 0;
    void helper(int n,int curr){
        if(curr < maxi){
            count++;
        }
        else{
            return;
        }
        
        for(int i = 0;i<=9;i++){
           int temp = curr;
           bool found = false;
           while(temp != 0){
             if(temp%10 == i){
                found = true;
                break;
             }
             temp /= 10;
           }
           if(found == false){
             temp = curr*10 + i;
             if(temp >= maxi){
                break;
             }
             if(temp == 0){
                continue;
             }
             helper(n,temp);
           }
        }
        return;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
       maxi = pow(10,n);
       helper(n,0);
       return count;
    }
};