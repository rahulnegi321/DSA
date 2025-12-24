class Solution {
public:
    // Use a set for result to avoid adding duplicate words
    set<string> result_set;

    void dfs(int row, int col, string &temp, vector<vector<char>>& board, 
             unordered_set<string>& wordSet, unordered_set<string>& prefixes) {
        
        // 1. Bounds check and Visited check
        // If out of bounds OR cell is visited ('#'), return
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#') {
            return;
        }

        // 2. Add current character to string
        temp += board[row][col];

        // 3. PRUNING (Crucial Step)
        // If the current string is NOT a prefix of any word, stop immediately.
        if (prefixes.find(temp) == prefixes.end()) {
            temp.pop_back(); // Backtrack: Remove the char before returning
            return;
        }

        // 4. Check if it is a full word
        if (wordSet.count(temp)) {
            result_set.insert(temp);
        }

        // 5. Mark as visited
        char original = board[row][col];
        board[row][col] = '#'; 

        // 6. Traverse 4 directions
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            dfs(row + drow[i], col + dcol[i], temp, board, wordSet, prefixes);
        }

        // 7. Backtrack: Restore board and string
        board[row][col] = original;
        temp.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        result_set.clear();
        unordered_set<string> wordSet(words.begin(), words.end());
        unordered_set<string> prefixes;

        // Pre-processing: Generate all prefixes
        // Example: if word is "apple", add "a", "ap", "app", "appl", "apple"
        for (string w : words) {
            string p = "";
            for (char c : w) {
                p += c;
                prefixes.insert(p);
            }
        }

        int n = board.size();
        int m = board[0].size();
        string temp = "";

        // Iterate over every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, temp, board, wordSet, prefixes);
            }
        }

        // Convert set to vector for final output
        return vector<string>(result_set.begin(), result_set.end());
    }
};