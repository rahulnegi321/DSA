class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        unordered_map<int, map<long long, int>> mpp;
        long long count = 0;
        long long sum = 0;
        vector<long long> pre;

        for (auto it : capacity) {
            sum = sum + it;
            pre.push_back(sum);
        }

        int n = capacity.size();
        
        for (int i = 2; i < n; i++) {
            int j = i - 2;
            mpp[capacity[j]][pre[j]]++;
            
            if (mpp.count(capacity[i])) {
                long long target_pre_j = pre[i] - (long long)2 * capacity[i];
                
                if (mpp[capacity[i]].count(target_pre_j)) {
                    count += mpp[capacity[i]][target_pre_j];
                }
            }
        }
        
        return count;
    }
};