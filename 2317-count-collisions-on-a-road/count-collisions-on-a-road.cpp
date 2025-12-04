class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int n = directions.size();
        int l = 0;
        int s  = 0;
        for(int i = n-1;i>=0;i--){
            if(directions[i] == 'L'){
                l++;
            }
            else if(directions[i] == 'S'){
               if(l != 0){
                count = count + l;
                l = 0;
               }
               s = 1;
            }
            else if(directions[i] == 'R'){
                if(l != 0){
                    count = count + l + 1;
                    s = 1;
                    l = 0;
                }
                else if(s != 0){
                    count = count + 1;
                }
            }
        }
        return count;
    }
};