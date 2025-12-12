class Solution {
public:
   
   string toBinary(int n){
        if(n == 0){
            return "0";
        }
        string s = "";
        while(n > 0){
            s += (n&1)?'1':'0';
            n >>= 1;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    int binaryToDecimal(const string &binary) {
    int decimal = 0;

    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}


    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>temp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
          string binary = toBinary(nums[i]);
          reverse(binary.begin(),binary.end());
          int converted = binaryToDecimal(binary);
          temp.push_back({converted,nums[i]});
        }
        sort(temp.begin(),temp.end());
        for(auto it : temp){
            ans.push_back(it.second);
        }
        return ans;
        }
};