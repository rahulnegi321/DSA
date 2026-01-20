class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>lastrun;
        unordered_map<char,int>count;
        for(int i = 0;i<tasks.size();i++){
            count[tasks[i]]++;
        }
        int total = tasks.size();
        priority_queue<pair<int,char>>q;
        for(auto it : count){
            q.push({it.second,it.first});
        }
        int start = 1;
        while(total){
           vector<pair<int,char>>temp;
           while(q.size()){
              auto it = q.top();
              q.pop();
              if(lastrun[it.second] == 0 || start - lastrun[it.second] > n){
                lastrun[it.second] = start;
                 int c = it.first-1;
                 char k = it.second;
                 total--;
                 if(c == 0){
                    break;
                 }
                 q.push({c,k});
                 break;
              }
              else{
                temp.push_back(it);
              }
           }
           for(int i = 0;i<temp.size();i++){
             q.push(temp[i]);
           }
           if(total == 0){
            break;
           }
           start++;
        }
        return start;
    }
};