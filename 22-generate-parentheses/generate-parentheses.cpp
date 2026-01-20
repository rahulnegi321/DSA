class Solution {
public:
    set<string>result;
    void helper(int count,int n,string& temp){
        if(count == 0 && n == 0){
            result.insert(temp);
            return;
        }
        if(count > 0){
            temp += ')';
            helper(count-1,n-1,temp);
            temp.pop_back();
        }
        if(count < n){
            temp += '(';
            helper(count+1,n,temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int count = 0;
        string temp = "";
        helper(0,n,temp);
        vector<string>ans(result.begin(),result.end());
        return ans;
    }
};