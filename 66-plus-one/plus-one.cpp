class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for(int i = n-1;i>=0;i--){
            int temp = digits[i];
            temp++;
            digits[i] = temp%10;
            carry = temp/10;
            if(carry == 0){
                break;
            }
        }
        if(carry != 0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};