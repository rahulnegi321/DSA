class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>total;
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i = 0;i<nums1.size();i++){
            total[nums1[i]]++;
            total[nums2[i]]++;
            mpp1[nums1[i]]++;
            mpp2[nums2[i]]++;
        }
        for(auto it : total){
            if(it.second%2 != 0){
                return -1;
            }
        }
        if(mpp1 == mpp2){
            return 0;
        }
        
        int count1 = 0;
        int count2 = 0;
        
        for(auto it : total){
            int curr = it.first;
            int c1 = mpp1[curr];
            int c2 = mpp2[curr];
            if(c1 == c2){
                continue;
            }
            else if(c1 > c2){
                int temp = c1-c2;
                count1 += temp/2;
            }
            else{
                int temp = c2-c1;
                count2 += temp/2;
            }
        }
        return max(count1,count2);
    }
};