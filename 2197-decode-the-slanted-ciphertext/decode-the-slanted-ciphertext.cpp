class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans = "";
        int m = encodedText.size();
        int n = m/rows;
        for(int i = 0;i<n;i++){
          for(int j = 0;i+j<m;j=j+n+1){
          
                ans += encodedText[i+j];
          }
        }
        while(ans.size() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};