class Solution {
public:
    int numSub(string s) {
        int M = 1e9+7;
        long long start = 0;
        int n = s.size();
        long long count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1'){
                start++;
            }
            else{
              count = (count + (start*(start+1)/2)%M)%M;
              start = 0;
            }
        }
        if(start != 0){
            count = (count + (start*(start+1)/2)%M)%M;
        }
        return (int)count;
    }
};