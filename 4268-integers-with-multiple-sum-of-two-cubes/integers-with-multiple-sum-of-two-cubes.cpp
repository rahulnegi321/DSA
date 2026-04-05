class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int i = 1;
        vector<int>cube;
        while(i*i*i < n){
           cube.push_back(i*i*i);
           i++;
        }
        vector<int>ans;
        int size = cube.size();
        unordered_map<int,int>mpp;
        for(int i = 0;i<size;i++){
            for(int j = i;j<size;j++){
                if(cube[i]+cube[j] <= n){
                    mpp[cube[i] + cube[j]]++;
                }
                else{
                    continue;
                }
            }
        }
        for(auto it : mpp){
            if(it.second >= 2){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};