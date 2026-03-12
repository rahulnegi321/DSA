class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
           
           string s1 = to_string(a);
           string s2 = to_string(b);  
           return s1+s2 > s2+s1;
        });
        string ans = "";
        for(int i = 0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            ans += temp;
        }
        int i = 0;
        int n = ans.size();
        while(i < n && ans[i] == '0'){
            i++;
        }
        if(i == n){
            return "0";
        }
        return ans.substr(i,n-i+1);
    }
};