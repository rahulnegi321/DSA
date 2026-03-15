class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>color(n,0);
        vector<int>ans;
        int count  = 0;
        for(auto it : queries){
            int ind = it[0];
            int col = it[1];
            if(color[ind] == 0){
                if(ind > 0 && ind < n-1 && col == color[ind-1] && col == color[ind+1]){
                    count = count+2;
                }
                else if(ind > 0 && col == color[ind-1]){
                    count++;
                }
                else if(ind < n-1 && col == color[ind+1]){
                    count++;
                }
                color[ind] = col;
            }
            else{
                int prev = color[ind];
                if(ind > 0 && ind < n-1 && prev == color[ind-1] && prev == color[ind+1]){
                    count = count-2;
                }
                else if(ind > 0 && prev == color[ind-1]){
                    count--;
                }
                else if(ind < n-1  && prev == color[ind+1]){
                    count--;
                }
                color[ind] = col;
                if(ind > 0 && ind < n-1 && col == color[ind-1] && col == color[ind+1]){
                    count = count+2;
                }
                else if(ind > 0 && col == color[ind-1]){
                    count++;
                }
                else if(ind < n-1 && col == color[ind+1]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};