class Solution {
public:
    int findComplement(int num) {
        int n = num;
        if(n == 0){
            return 1;
        }
        string temp = "";
        while(n != 1){
            temp += (char)((n%2)+'0');
            n /= 2;
        }
        temp += '1';
        reverse(temp.begin(),temp.end());
        for(int i = 0;i<temp.size();i++){
            if(temp[i] == '0'){
                temp[i] = '1';
            }
            else{
                temp[i] = '0';
            }
        }
        int count = 0;
        int ans = 0;
        int N = temp.size();
        for(int i = N-1;i>=0;i--){
            if(temp[i] == '1'){
                ans += pow(2,count);
            }
            count++;
        }
        return ans;
    }
};