class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int total = accumulate(apple.begin(),apple.end(),0);
        int count = 0;
        for(int i = 0;i<capacity.size();i++){
            total = total-capacity[i];
            count++;
            if(total <= 0){
                return count;
            }
        }
        return count;
    }
};