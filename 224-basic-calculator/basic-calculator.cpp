class Solution {
public:
    int calculate(string s) {
        int count = 0;
        int n = s.size();
        stack<string>st;
        st.push("+");
        for(int i = 0;i<n;i++){
           if(s[i] == ' '){
            continue;
           }
           if(s[i] == '+' || s[i] == '-' || s[i] == '('){
            string temp = "";
            temp += s[i];
            st.push(temp);
           }
           if(isdigit(s[i])){
             string temp = "";
             while(i < n && isdigit(s[i])){
                temp += s[i];
                i++;
             }
             i--;
             st.push(temp);
           }
           if(s[i] == ')'){
              stack<string>temp;
              while(st.top() != "("){
                temp.push(st.top());
                st.pop();
              }
              st.pop();
              long long ans = 0;
              char sign = '+';
              while(temp.size()){
                 if(temp.top() == "+"){
                    sign = '+';
                 }
                 else if(temp.top() == "-"){
                    sign = '-';
                }
                else{
                    long long t = stoll(temp.top());
                    if(sign == '-'){
                        ans -= t;
                    }
                    else{
                        ans += t;
                    }
                }
                temp.pop();
              }
              string curr = to_string(ans);
              st.push(curr);
           }
        }
        stack<string>temp;
        while(st.size()){
            temp.push(st.top());
            st.pop();
        }
        long long ans = 0;
        char sign = '+';
        while(temp.size()){
            if(temp.top() == "+"){
              sign = '+';
            }
            else if(temp.top()  == "-"){
                sign = '-';
            }
            else{
                long long curr = stoll(temp.top());
                if(sign == '+'){
                    ans += curr;
                }
                else{
                    ans -= curr;
                }
            }
            temp.pop();
        }
        return (int)ans;
    }
};