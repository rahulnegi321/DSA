class Solution {
public:
    int reverse(int x) {
        long long k = x;
        if(x == 0){
            return x;
        }
        bool neg = false;
        if(k < 0){
            neg = true;
            k = -k;
        }
        string temp = to_string(k);
       std::reverse(temp.begin(), temp.end());
        long long conv = stoll(temp);
        if(neg){
            conv = -conv;
        }
        if(conv >= INT_MAX || conv <= INT_MIN){
            return 0;
        }
        return (int)conv;
    }
};