class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        unordered_map<int,int>mpp;
        vector<int>ans(numberOfUsers);
        sort(events.begin(), events.end(),
         [](const vector<string>& a, const vector<string>& b) {
             int t1 = stoi(a[1]);
             int t2 = stoi(b[1]);

             if (t1 != t2)
                 return t1 < t2;

             if (a[0] != b[0])
                 return a[0] == "OFFLINE";

             return false;
         });

        for(auto it : events){
            if(it[0] == "MESSAGE" && it[2] == "HERE"){
                  int time = stoi(it[1]);
               for(int i = 0;i<numberOfUsers;i++){
                if(mpp[i] > time){
                    continue;
                }
                else{
                    ans[i]++;
                }
               }
            }
            else if(it[0] == "MESSAGE" && it[2] == "ALL"){
                for(int i = 0;i<numberOfUsers;i++){
                    ans[i]++;
               }
            }
            else if(it[0] == "MESSAGE"){
               unordered_map<int,int>t;
               string temp = "";
               string total = it[2];
               for(int i = 0;i<it[2].size();i++){
                  if(total[i] == ' '){
                    int o = stoi(temp);
                    t[o]++;
                    temp = "";
                  }
                  else{
                    if(total[i] == 'i' || total[i] == 'd'){
                       continue;
                    }
                    else{
                        temp += total[i];
                    }
                  }
               }
               int o = stoi(temp);
               t[o]++;
               for(auto k :t){
                 ans[k.first] = ans[k.first] + k.second;
               }
            }
            else{
              int time = stoi(it[1]);
              int id = stoi(it[2]);
              int temp = mpp[id];
              mpp[id] = max(temp,time + 60);
            }
        }
        return ans;
    }
};