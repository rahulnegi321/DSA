class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int count  = 0;
        vector<pair<int,int>>temp;
        for(int i = 0;i<position.size();i++){
            temp.push_back({position[i],speed[i]});
        }
        sort(temp.begin(),temp.end());
        vector<double>time;
        for(auto it : temp){
            double curr = ((double)target-(double)it.first)/(double)it.second;
            time.push_back(curr);
        }
        stack<double>st;
        int n = speed.size();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top() < time[i]){
                st.pop();
            }
            if(st.empty()){
                count++;
                st.push(time[i]);
            }
            else{
                st.push(time[i]);
            }
        }
        return count;
    }
};