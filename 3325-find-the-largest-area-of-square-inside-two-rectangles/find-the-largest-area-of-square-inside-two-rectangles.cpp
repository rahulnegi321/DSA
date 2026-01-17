class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                pair<int,int> bl1 = {bottomLeft[i][0], bottomLeft[i][1]};
                pair<int,int> tr1 = {topRight[i][0], topRight[i][1]};

                pair<int,int> bl2 = {bottomLeft[j][0], bottomLeft[j][1]};
                pair<int,int> tr2 = {topRight[j][0], topRight[j][1]};

                int inter_bl_x = max(bl1.first, bl2.first);
                int inter_bl_y = max(bl1.second, bl2.second);
                int inter_tr_x = min(tr1.first, tr2.first);
                int inter_tr_y = min(tr1.second, tr2.second);

                if(inter_tr_x > inter_bl_x && inter_tr_y > inter_bl_y) {
                    long long temp1 = inter_tr_x - inter_bl_x;
                    long long temp2 = inter_tr_y - inter_bl_y;
                    long long temp = min(temp1, temp2);
                    ans = max(ans, temp * temp);
                }
            }
        }
        return ans;
    }
};