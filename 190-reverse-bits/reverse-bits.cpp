class Solution {
public:
    int reverseBits(int n) {
        if(n == 0){
            return 0;
        }
        int count = 0;
        string temp = "";
        for(int i = 0;i<32;i++){
           temp += (char)(n%2 + '0');
            n /= 2;
        }
        
        int  k = temp.size();
        int ans = 0;
        for(int i = k-1;i>=0;i--){
           if(temp[i] == '1'){
              ans += pow(2,count);
           }
           count++;
        }
        return ans;
    }
};