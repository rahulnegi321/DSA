class Solution {
public:
    string invert(string s){
       string temp = "";
       for(int i = 0;i<s.size();i++){
        if(s[i] == '0'){
            temp += '1';
        }
        else{
            temp += '0';
        }
       }

       return temp;
    }
    string s(int n){
        if(n == 1){
            return "0";
        }
        string temp = "";
        string prev = s(n-1);
        temp = prev + "1";
        string inverted = invert(prev);
        reverse(inverted.begin(),inverted.end());
        temp += inverted;
        return temp;
    }
    char findKthBit(int n, int k) {
        string temp = s(n);
        return temp[k-1];
    }
};