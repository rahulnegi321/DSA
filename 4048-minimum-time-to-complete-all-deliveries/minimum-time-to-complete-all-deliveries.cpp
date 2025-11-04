class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = 0;
        long long high = max(100LL,(d[0]+d[1])*1LL*max(r[0],r[1]));
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long x1 = mid - mid/r[0];
            long long x2 = mid - mid/r[1];
            long long x3 = mid - (mid/r[0] + mid/r[1] - mid/lcm(r[0],r[1]));
            if(x1 >= d[0] && x2 >= d[1] && x1 + x2 - x3 >= d[0] + d[1]){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};