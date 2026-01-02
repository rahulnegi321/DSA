class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int n = s.size();
        string ans = "";
         int temp = 2*numRows - 2;
         int first = temp;
        for(int i = 0;i<numRows;i++){
            for(int j = i;j<s.size();j = j+temp){
               ans += s[j];
               if(first == temp || first == 0){
                continue;
               }
               if(j+ first >= n){
                continue;
               }
               ans += s[j+first];
            }
            first -= 2;
        }
        return ans;
    }
};