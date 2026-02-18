class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 1){
            return true;
        }
        string temp = "";
        while(n != 1){
            temp += (char)(n%2 + '0');
            n /= 2;
        }
        temp += "1";
        for(int i = 0;i<temp.size()-1;i++){
            if(temp[i] == temp[i+1]){
                return false;
            }
        }
        return true;
    }
};