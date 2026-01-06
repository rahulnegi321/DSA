class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> one;
        unordered_map<int, int> mpp;
        for (auto res : restrictions) mpp[res[0]] = res[1];

        one.push_back(0);
        for (int i = 0; i < diff.size(); i++) {
            if (mpp.count(i + 1)) {
                one.push_back(min(mpp[i + 1], diff[i] + one.back()));
            } else {
                one.push_back(diff[i] + one.back());
            }
        }

     
        for (int i = n - 2; i >= 0; i--) {
            one[i] = min(one[i], one[i + 1] + diff[i]);
        }

        return *max_element(one.begin(), one.end());
    }
};