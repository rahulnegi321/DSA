class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char,char>,int>dis;
        priority_queue<pair<int,pair<char,char>>,vector<pair<int,pair<char,char>>>,greater<pair<int,pair<char,char>>>>q;
        unordered_map<char,vector<pair<char,int>>>mpp;
        for(int i = 0;i<original.size();i++){
            q.push({cost[i],{original[i],changed[i]}});
            mpp[original[i]].push_back({changed[i],cost[i]});
        }
        while(q.size()){
            int dist = q.top().first;
            char curr = q.top().second.first;
            char to = q.top().second.second;
            q.pop();
            if(dis.count({curr,to})){
                continue;
            }
            dis[{curr,to}] = dist;
            for(auto it : mpp[to]){
                char temp = it.first;
                int charge = it.second;
                if(!dis.count({curr,temp})){
                    q.push({dist+charge,{curr,temp}});
                }
            }
        }
        long long count = 0;
        for(int i = 0;i<target.size();i++){
            if(source[i] == target[i]){
                continue;
            }
            if(!dis.count({source[i],target[i]})){
                return -1;
            }
            count += dis[{source[i],target[i]}];
        }
        return count;
    }
};