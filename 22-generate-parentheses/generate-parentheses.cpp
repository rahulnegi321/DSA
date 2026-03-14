class Solution {
public:
    set<string>result;
    int N;
    void helper(int count,int n,string ans){
        if(count == N && n == 0){
            result.insert(ans);
            return;
        }
        if(count < N){
            ans += '(';
            helper(count+1,n,ans);
            ans.pop_back();
        }
        if(n != 0 && count > N-n){
            ans += ')';
            helper(count,n-1,ans);
            ans.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        N = n;
        helper(0,n,ans);
        vector<string>finalans(result.begin(),result.end());
        return finalans;
    }
};