class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>temp;
        temp.insert(nums1.begin(),nums1.end());
        temp.insert(nums2.begin(),nums2.end());
        vector<int>ans(temp.begin(),temp.end());
        int n = ans.size();
        if(n == 1){
            return (double)ans[0];
        }
        if(n%2 == 1){
            return (double)ans[n/2];
        }
        double finalans = ((double)ans[(n-1)/2]+(double)ans[n/2])/2;
        return finalans;
    }
};