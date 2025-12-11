class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
       vector<vector<int>> x(n + 1), y(n + 1);
        for(auto it : buildings){
            x[it[0]].push_back(it[1]);
            y[it[1]].push_back(it[0]);
        }
        for(auto & it : x){
            sort(it.begin(),it.end());
        }
        for(auto & it:y){
            sort(it.begin(),it.end());
        }
        int count = 0;
        for(auto it : buildings){
            int x1 = it[0];
            int y1 = it[1];
            if(x[x1][0] < y1 && x[x1].back() > y1 && y[y1][0] < x1 && y[y1].back() > x1){
                count++;
            }
        }
         return count;
    }
};