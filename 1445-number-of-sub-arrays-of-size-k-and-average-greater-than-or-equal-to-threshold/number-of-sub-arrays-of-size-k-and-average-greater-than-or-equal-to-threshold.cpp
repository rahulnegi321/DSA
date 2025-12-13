class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        long long sum = 0;
        int left = 0;
        for(int i = 0;i<arr.size();i++){
            sum = sum + arr[i];
            if(i-left+1 > k){
                sum = sum - arr[left];
                left++;
            }
            if(i-left+1 == k){
                if(sum/k >= threshold){
                    count++;
                }
            }
        }
        return count;
    }
};