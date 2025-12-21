class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        int ans = 0;
        int j = 0;
        int n = tasks.size();
        for(int i = 0;i<processorTime.size();i++){
            int count = 0;
            while(j<n){
                ans = max(ans,processorTime[i] + tasks[j]);
                j++;
                count++;
                if(count == 4){
                    break;
                }
            }
        }
        return ans;
    }
};