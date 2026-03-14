class Solution {
public:
    string ans = "";
    int count = 0;
    void helper(string &curr,int n,int k){
        if(count > k){return;}
        if(curr.size() == n){
           count++;
           if(count == k){
            ans = curr;
            return;}}
        if(curr.size() < n){
             for(char i = 'a';i<='c';i++){
            if(curr.size() == 0){
                curr += i;
                helper(curr,n,k);
                curr.pop_back();}
            else{char temp = curr.back();if(temp == i){continue;}
                curr += i;
                helper(curr,n,k);
                curr.pop_back();}}}
        return;}
    string getHappyString(int n, int k) {
       string temp = "";
       helper(temp,n,k);
       return ans;
    }
};