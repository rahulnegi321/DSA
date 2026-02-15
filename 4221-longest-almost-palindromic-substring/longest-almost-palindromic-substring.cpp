class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 2;

        vector<vector<bool>>ispal(n,vector<bool>(n,0));
        for(int i = n-1;i>=0;i--){
            ispal[i][i] = 1;
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i == 1){
                        ispal[i][j] = 1;
                    }
                    else{
                        ispal[i][j] = ispal[i+1][j-1];
                    }
                }
            }
        }

        vector<vector<int>>dp2(n,vector<int>(n,0));
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(i+1 < j-1){
                        dp2[i][j] = 1 + dp2[i+1][j-1];
                    }
                    else{
                        dp2[i][j] = 1;
                    }
                }
            }
        }

        for(int temp = n;temp>=2;temp--){
            for(int i = 0;i + temp <= n;i++){
                int j = i + temp -1;
                int dummy = dp2[i][j];

                if(dummy >= temp/2){
                    return temp;
                }
                int left = i + dummy;
                int right = j - dummy;

                if(ispal[left+1][right] || ispal[left][right-1]){
                    return temp;
                }
            }
        }
        return 2;
    }
};