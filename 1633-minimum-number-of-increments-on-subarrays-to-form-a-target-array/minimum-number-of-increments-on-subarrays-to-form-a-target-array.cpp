class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0;
        int count = 0;
        int n = target.size();
        int i= 0;
        while(i<n){
            while(i+1 < n && target[i+1] >= target[i]){
                i++;
            }
            count = count + target[i]-prev;
            if(i+1 == n){
               break;
            }
            while(i+1 < n && target[i+1] <= target[i]){
                i++;
            }
            prev = target[i];
            if(i+1 == n){
                break;
            }
        }
        return count;
    }
};