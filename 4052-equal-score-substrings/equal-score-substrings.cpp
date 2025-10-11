class Solution {
public:
    bool scoreBalance(string s) {
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            sum = sum + (int)(s[i]-'a')+1;
        }
        if(sum%2 == 1){
            return false;
        }
        int temp = 0;
        for(int i = 0;i<s.size();i++){
           temp = temp + (int)(s[i]-'a')+1;
           if(temp == sum/2){
            return true;
           }

        }
        return false;
    }
};