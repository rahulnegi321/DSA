#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

class Solution {
public:
    // This helper now finds the MAXIMUM VALUE reachable from (i, j)
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: If out of bounds, return a very small number
        if (i >= n || j >= m) {
            return INT_MIN;
        }

        if (dp[i][j] != -1) { // A more standard initial value
            return dp[i][j];
        }

        // Find the max value reachable from the right or down
        int max_future_val = max(helper(grid, dp, i + 1, j), helper(grid, dp, i, j + 1));
        
        // The max value from here is either the current cell's value or the max from a future cell
        return dp[i][j] = max(grid[i][j], max_future_val);
    }

    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = INT_MIN;

        // Pre-calculate all max future values using your helper
        helper(grid, dp, 0, 0);

        // Now, find the max score
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Find the max value reachable from the next step (right or down)
                int max_future_val = INT_MIN;
                if (i + 1 < n) {
                    max_future_val = max(max_future_val, dp[i + 1][j]);
                }
                if (j + 1 < m) {
                    max_future_val = max(max_future_val, dp[i][j + 1]);
                }

                // If a move is possible, calculate the score
                if (max_future_val != INT_MIN) {
                    ans = max(ans, max_future_val - grid[i][j]);
                }
            }
        }
        return ans;
    }
};