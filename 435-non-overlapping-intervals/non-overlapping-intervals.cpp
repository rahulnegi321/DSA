class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        vector<vector<int>>merge;
        sort(intervals.begin(),intervals.end());
        for(auto it : intervals){
            int start = it[0];
            int end = it[1];
            if(merge.empty()){
                merge.push_back(it);
            }
            else if(merge.back()[1] > start){
                if(merge.back()[1] > end){
                    merge.pop_back();
                    merge.push_back(it);
                }
            }
            else{
                merge.push_back(it);
            }
        }
        return intervals.size()-merge.size();
    }
};