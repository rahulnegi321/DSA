class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        int seats = 0;
        int plants = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;
                if (seats > 2 && seats % 2 == 1) {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0;
                }
            } else {
                if (seats >= 2 && seats % 2 == 0) {
                    plants++;
                }
            }
        }

        return (seats % 2 == 0 && seats > 0) ? ans : 0;
    }
};
