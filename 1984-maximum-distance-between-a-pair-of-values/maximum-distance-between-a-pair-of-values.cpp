class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp = nums2;
        reverse(temp.begin(),temp.end());
        int ans = 0;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
               auto it = lower_bound(temp.begin(),temp.end()-i,nums1[i]);
               int ind = it - temp.begin();
               int j = nums2.size()-ind-1;
               ans = max(ans,j-i);
        }
        return ans;
    }
};