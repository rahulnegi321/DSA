class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char,char>,int>mpp;
        priority_queue<pair<int,pair<char,char>>,vector<pair<int,pair<char,char>>>,greater<pair<int,pair<char,char>>>>q;
        for(int i = 0;i<original.size();i++){
            q.push({cost[i],{original[i],changed[i]}});
        }
        unordered_map<char,vector<pair<char,int>>>adj;
        for(int i = 0;i<original.size();i++){
            adj[original[i]].push_back({changed[i],cost[i]});
        }
        while(q.size()){
            int paise = q.top().first;
            int so = q.top().second.first;
            int ta = q.top().second.second;
            q.pop();
            if(mpp.count({so,ta})){
                continue;
            }
            mpp[{so,ta}] = paise;
            for(auto it : adj[ta]){
                char temp = it.first;
                int pa = it.second;
                if(mpp.count({so,temp})){
                    continue;
                }
                if(temp == so){
                    continue;
                }
                q.push({paise+pa,{so,temp}});
            }
        }
        long long ans = 0;
        for(int i = 0;i<source.size();i++){
            if(source[i] == target[i]){
                continue;
            }
            if(!mpp.count({source[i],target[i]})){
                return -1;
            }
            ans += mpp[{source[i],target[i]}];
        }
        return ans;
    }
};