class Solution {
public:
    long long M = 1e9+7;

    long long comb2(long long n){
        if(n < 2) return 0;
        return (n * (n - 1) / 2) % M;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,long long> mpp;

        for(auto &p : points){
            mpp[p[1]]++;
        }

        long long total = 0;
        for(auto &it : mpp){
            total = (total + comb2(it.second)) % M;
        }

        long long ans = 0;

        for(auto &it : mpp){
            long long c = comb2(it.second);
            if(c == 0) continue;

            total = (total - c + M) % M;
            ans = (ans + (c * total) % M) % M;
        }

        return ans;
    }
};
