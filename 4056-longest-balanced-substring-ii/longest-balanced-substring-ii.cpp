class Solution {
public:
    int helper(string& s,char a,char b){
       int counta = 0;
       int countb = 0;
       unordered_map<int,int>mpp;
       int maxl = 0;
       for(int i = 0;i<s.size();i++){
         if(s[i] == a){
            counta++;
         }
         else if(s[i] == b){
            countb++;
         }
         else{
            mpp.clear();
            counta = 0;
            countb = 0;
         }
         if(counta == countb){
            maxl = max(maxl,counta+countb);
         }
         int temp = counta-countb;
         if(mpp.count(temp)){
            maxl = max(maxl,i-mpp[temp]);
         }
         else{
            mpp[temp] = i;
         }
       }
       return maxl;
    }
    int longestBalanced(string s) {
        int count = 1;
        int maxl = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]){
                count++;
            }
            else{
                count = 1;
            }
            maxl = max(maxl,count);
        }
        
        //case2
        int temp1 = helper(s,'a','b');
        int temp2 = helper(s,'a','c');
        int temp3 = helper(s,'b','c');
        maxl = max({maxl,temp1,temp2,temp3});

        //case3

        unordered_map<string,int>mpp;
        int counta = 0;
        int countb = 0;
        int countc = 0;
        mpp["0_0"] = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a'){
                counta++;
            }
            else if(s[i] == 'b'){
                countb++;
            }
            else{
                countc++;
            }
            if(counta == countb && countc == countb){
                maxl = max(maxl,counta+countb+countc);
            }
            int diff1 = counta - countb;
            int diff2 = counta - countc;
            string temp = to_string(diff1) + "_" + to_string(diff2);
            if(mpp.count(temp)){
                maxl = max(maxl,i-mpp[temp]);
            }
            else{
                mpp[temp] = i;
            }
        }
        return maxl;
    }
};