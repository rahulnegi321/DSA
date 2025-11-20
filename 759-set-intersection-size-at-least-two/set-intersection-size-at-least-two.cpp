using namespace std;
class Solution {
public:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1]; 
    }
    return a[0] > b[0];
}
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        int count = 2;
        int a  = intervals[0][1]-1;
        int b = intervals[0][1];
        int n = intervals.size();
        for(int i = 1;i<n;i++){
           if(a >= intervals[i][0] && b >= intervals[i][0] && a <= intervals[i][1] && b <= intervals[i][1]){
             continue;
           }
           else if(b <= intervals[i][1] && b >= intervals[i][0]){
             a = b;
             b = intervals[i][1];
             count++;
           }
           else{
            a = intervals[i][1]-1;
            b = intervals[i][1];
            count = count+2;
           }
        }
        return count;
    }
};