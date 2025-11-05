class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1;
        long long high = 2*1e9;
        long long ans = 0;
        long long a1 = a;
        long long b1 = b;
        long long c1 = c;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long x1 = mid/a1 + mid/b1 + mid/c1 - mid/lcm(a1,b1) - mid/lcm(a1,c1) - mid/lcm(b1,c1) + mid/lcm(a1,lcm(b1,c1));
            if(x1 >= n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};