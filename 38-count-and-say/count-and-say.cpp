class Solution {
public:
    string countAndSay(int n) {
      string ans = "1";
      if(n == 1){
        return ans;
      }
      int count  = 1;
      while(count < n){
        int i = 0;
        string temp = "";
        while(i<ans.size()){
          int c = 1;
          char k = ans[i];
          while(i+1 < ans.size() && ans[i] == ans[i+1]){
            i++;
            c++;
          }
          temp = temp + (char)(c+'0') + k;
          i++;
        }
        ans = temp;
        count++;
      }
      return ans;
    }
};