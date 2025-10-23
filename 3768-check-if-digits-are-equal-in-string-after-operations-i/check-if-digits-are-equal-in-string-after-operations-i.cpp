class Solution {
public:
    bool hasSameDigits(string s) {
        string temp = "";
        while(s.size() != 2){
          for(int i=0;i<s.size()-1;i++){
            int a = s[i]-'0';
            int b = s[i+1]-'0';
            int c = (a+b)%10;
            char t = (char)(c+'0');
            temp.push_back(t);
          }
          s = temp;
          temp = "";
        }
        if(s[0] == s[1]){
            return true;
        }
        return false;
    }
};