class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>temp;
        for(int i = 1;i<=n;i++){
            temp.push_back(i);
        }
        int start = 0;
        while(temp.size() > 1){

        int to_remove = (start + k - 1)%(temp.size());
        temp.erase(temp.begin()+to_remove);
        start = to_remove; 
        }
        return temp[0];
    }
};