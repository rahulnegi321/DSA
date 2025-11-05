class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long c1 = uniqueCnt1;
        long long c2 = uniqueCnt2;
        long long d1 = divisor1;
        long long d2 = divisor2;
        long long low = 1;
        long long ans = 1;
        long long high = max(100LL,(c1+c2)*1LL*(max(d1,d2)));
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long x1 = mid - mid/d1;
            long long x2 = mid - mid/d2;
            long long x3 = mid - (mid/d1 + mid/d2 - mid/lcm(d1,d2));
            if(x1 >= c1 && x2 >= c2 && x1 + x2 - x3 >= c1+c2 ){
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        return (int)ans;
    }
};