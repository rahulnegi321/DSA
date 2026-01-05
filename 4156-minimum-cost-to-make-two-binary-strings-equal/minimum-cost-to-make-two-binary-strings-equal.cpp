class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        if(s == t){
            return 0;
        }
        int count11 =  0;
        int count12 = 0;
        int conf = 0;
        long long ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                count11++;
            }
            if(t[i] == '1'){
                count12++;
            }
            if(s[i] != t[i]){
                conf++;
            }
        }
        long long temp = conf*1LL*flipCost;
        if((count11 + count12)%2 != 0){
            ans += flipCost;
            if(count11 < count12){
                count11++;
                conf--;
            }
            else{
                count12++;
                conf--;
            }
        }
        if(conf == 0){
            return ans;
        }
        while(count11 != count12){
            if(2*flipCost < swapCost+crossCost){
                conf = conf-2;
                ans += 2*flipCost;
                if(count11 < count12){
                    count11 += 2;
                } 
                else{
                    count12 += 2;
                }
            }
            else{
                ans += crossCost;
                 if(count11 < count12){
                    count11 += 1;
                    count12 -= 1;
                } 
                else{
                    count12 += 1;
                    count11 -= 1;
                }
            }
        }
        if(conf){
            long long t = ((conf+1)/2)*1LL*swapCost;
            long long p = conf*1LL*flipCost;
            ans = ans + min(t,p);
        }
        return min(ans,temp);
    }
};