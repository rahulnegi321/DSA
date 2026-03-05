class Solution {
public:
    int minOperations(string s) {
        int start1 = 0;
        for(int i = 0;i<s.size();i=i+2){
            if(s[i] == '0'){
                start1++;
            }
            if(i+1 < s.size()){
                if(s[i+1] == '1'){
                    start1++;
                }
            }
        }
        int start0 = 0;

        for(int i = 0;i<s.size();i=i+2){
            if(s[i] == '1'){
                start0++;
            }
            if(i+1 < s.size()){
                if(s[i+1] == '0'){
                    start0++;
                }
            }
        }
        return min(start0,start1);
    }
};