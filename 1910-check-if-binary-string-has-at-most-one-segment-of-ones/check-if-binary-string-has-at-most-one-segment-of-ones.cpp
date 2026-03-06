class Solution {
public:
    bool checkOnesSegment(string s) {
       int count = 0;
       for(int i = 0;i<s.size();i++){
        if(s[i] == '1' && count != 0 && s[i-1] == '0'){
            return false;
        }
         if(s[i] == '1'){
            count++;
         }
       }
       return true;
    }
};