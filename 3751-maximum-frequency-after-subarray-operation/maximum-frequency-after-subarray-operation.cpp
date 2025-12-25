class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        // OPTIMIZATION 1: Use vector instead of map for speed
        vector<int> count_of_k(n + 1, 0); 
        int total_k = 0;
        
        // Precompute 'k' counts
        for(int i = 0; i < n; i++){
            if(nums[i] == k) total_k++;
            count_of_k[i+1] = total_k;
        }

        int global_max = total_k; // Replaces priority_queue logic

        for(int i = 1; i <= 50; i++){
            if(i == k) continue;

            // OPTIMIZATION 2: Use simple variables instead of map 'mpp'
            int current_target_count = 0;
            
            // These replace your 'coi' and 'cok' maps
            int min_diff = 0; 

            for(int j = 0; j < n; j++){
                if(nums[j] == i) current_target_count++;

                int current_k_count = count_of_k[j+1];

                // YOUR LOGIC: (Target Count - K Count)
                int diff = current_target_count - current_k_count;

                // YOUR LOGIC: Update answer
                // Current Total = Original Total K + (Gain in this subarray)
                // Gain = Current Diff - Min Diff seen so far (effectively your 'start' logic)
                int current_gain = diff - min_diff;
                if (total_k + current_gain > global_max) {
                    global_max = total_k + current_gain;
                }

                // YOUR LOGIC: Reset 'start' if current diff is lower than best start
                if(diff < min_diff){
                    min_diff = diff;
                }
            }
        }
        return global_max;
    }
};