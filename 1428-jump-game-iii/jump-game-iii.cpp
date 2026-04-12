class Solution {
public:
    unordered_map<int,int>mpp;
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size()){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }
        if(mpp.count(start)){
            return false;
        }
        mpp[start]++;
        return (canReach(arr,start-arr[start]) | canReach(arr,start+arr[start]));
      }     
};