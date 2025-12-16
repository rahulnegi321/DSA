class Solution {
public:
    string resultingString(string s) {
       vector<char>st;
       int i = 0;
       int n = s.size();
       while(i < n){
         if(st.empty()){
            st.push_back(s[i]);
            i++;
         }
         else{
            char t = st.back();
            if ((t - s[i] + 26)%26 == 1 || (s[i] - t + 26)%26 == 1){
                st.pop_back();
                i++;
            }
            else{
                st.push_back(s[i]);
                i++;
            }
         }
       }
       string ans = "";
       for(auto it : st){
        ans += it;
       }
       return ans;
    }
};