class Solution {
public:
    int totalMoney(int n) {
     int start = 0;
     int ans = 0;
     for(int  i = 1;i<=n;i++){
        if(i%7 == 0){
            ans = ans + 7 + start;
            start++;
        }
        else{
            ans = ans + (i%7) + start;
        }
     }
     return ans;
    }
};