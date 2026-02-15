class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = n-1;
        int j = m-1;
        int carry = 0;
        string result = "";
        while(i>= 0|| j>=0 || carry ){
        int sum = carry;
        if(i>=0){
            sum = sum + int(a[i] - '0');
            i--;
        }
        if(j >= 0){
            sum = sum + int(b[j] - '0');
            j--;
        }
        carry = sum/2;
        
        result.push_back((sum%2) + '0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
};