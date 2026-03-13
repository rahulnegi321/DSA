class Solution {
public:
    int minOperations(string s) {
        string temp = s;

        sort(temp.begin(),temp.end());
        if(temp == s){
            return 0;
        }
        int n = s.size();
        if(n == 2){
            return -1;
        }
        if(s[0] == temp[0] || s[n-1] == temp[n-1]){
            return 1;
        }
        char mini = 'z';
        for(int i = 0;i<n;i++){
            mini = min(s[i],mini);
            if(mini == temp[0] && i < n-1){
               return 2;
            }
        }
        char maxi = 'a';
        for(int i = n-1;i>=1;i--){
            maxi = max(s[i],maxi);
            if(maxi == temp[n-1]){
                return 2;
            }
        }
        return 3;
    }
};