class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        for(int i = 1;i<points.size();i++){
            int temp1 = abs(points[i][0]-points[i-1][0]);
            int temp2 = abs(points[i][1]-points[i-1][1]);
            count += max(temp1,temp2);
        }
        return count;
    }
};