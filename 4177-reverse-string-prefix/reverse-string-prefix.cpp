class Solution {
public:
    string reversePrefix(string s, int k) {
        string temp = s.substr(0,k);
        string remain = s.substr(k);
        reverse(temp.begin(),temp.end());
        temp += remain;
        return temp;
    }
};