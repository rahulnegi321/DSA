class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        unordered_map<int,int>mpp;
        if(n == 1){
            return 1;
        }
        if(ratings[0] > ratings[1]){
           mpp[0] = 2;
        }
        else{
            mpp[0] = 1; 
        }
        for(int i = 1;i<n;i++){
            if(i+1 == n){
               if(ratings[i-1] < ratings[i]){
                  mpp[i] = mpp[i-1]+1;
               }
               else{
                mpp[i] = 1;
               }
               break;
            }
            if(ratings[i-1] < ratings[i] ){
                mpp[i]  = mpp[i-1]+1;
            }
            else{
                mpp[i] = 1;
            }
        }
        unordered_map<int,int>mpp2;
        mpp2[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            
            if(ratings[i] > ratings[i+1] ){
                mpp2[i]  = mpp2[i+1]+1;
            }
            else{
                mpp2[i] = 1;
            }
        }
        
        int ans = 0;
         for(int i =0;i<n;i++){
            ans += max(mpp[i],mpp2[i]);
         }
        return ans;
    }
};