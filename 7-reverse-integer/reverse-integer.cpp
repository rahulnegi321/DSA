class Solution {
public:
    int reverse(int x) {
        // long long k = x;
        if(x == 0){
            return x;
        }
        string help = "";
        if(x==INT_MIN){
            help += to_string(x%(-10));
            x /= 10;
        }
        bool neg = false;
        if(x < 0){
            neg = true;
            x = -x;
        }
        string temp = to_string(x);
        if(help.size() != 0){
           temp += help;
        }

        std::reverse(temp.begin(), temp.end());

        int maxp = INT_MAX;
        string maxi = to_string(maxp);
        int last = INT_MIN%(10);

        int minp = INT_MIN/(-10);
        string mini = to_string(minp);
        mini += to_string(abs(last));
        
        if(temp.size() < maxi.size()){
            return neg == false ? stoi(temp) : -(stoi(temp));
        }
        if(neg == false){
          for(int i =0;i<temp.size();i++){
            if(temp[i]-'0' > maxi[i]-'0'){
                return 0;
            }
            else if(temp[i]-'0' < maxi[i]-'0'){
                    break;
                }
        }
        }
        else{
            for(int i = 0;i<temp.size();i++){
                if(temp[i]-'0' > mini[i]-'0'){
                    return 0;
                }
                else if(temp[i]-'0' < mini[i]-'0'){
                    break;
                }
            }
        }
        int final = stoi(temp);
         return neg == false ? final : -(final);
    }
};