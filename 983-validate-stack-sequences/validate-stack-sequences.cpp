class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int n = pushed.size();
        stack<int>temp;
        int j = 0;
        while(i < n){
            if(!temp.empty() && temp.top() == popped[j]){
                temp.pop();
                j++;
            }
            else{
                temp.push(pushed[i]);
                i++;
            }
        }
        while(!temp.empty() && temp.top() == popped[j]){
           temp.pop();
           j++;
        }
        return temp.empty();
    }
};