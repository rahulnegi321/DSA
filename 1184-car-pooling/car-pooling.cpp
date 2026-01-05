class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int>mpp;
        int curr = 0;
        sort(trips.begin(),trips.end(),[](const vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });
        for(int i = 0;i<trips.size();i++){

            int start = trips[i][1];
            for(int j = 0;j<=start;j++){
                curr -= mpp[j];
                mpp[j] = 0;
            }
            curr += trips[i][0];
            if(curr > capacity){
                return false;
            }
            mpp[trips[i][2]] = mpp[trips[i][2]] + trips[i][0];
        }
        return true;
    }
};