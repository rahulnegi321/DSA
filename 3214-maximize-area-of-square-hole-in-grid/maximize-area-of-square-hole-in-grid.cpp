class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int count1 = 2;
        int maxi1 = 2;
        int count2 = 2;
        int maxi2 = 2;
        for(int i = 1;i<hBars.size();i++){
            if(hBars[i] == hBars[i-1]+1){
             count1++;
             maxi1 = max(maxi1,count1);
            }
            else{
                count1 = 2;
            }
        }
        for(int i = 1;i<vBars.size();i++){
            if(vBars[i] == vBars[i-1]+1){
                count2++;
                maxi2 = max(maxi2,count2);
            }
            else{
                count2 = 2;
            }
        }
        int temp = min(maxi1,maxi2);
        return temp*temp;
    }
};