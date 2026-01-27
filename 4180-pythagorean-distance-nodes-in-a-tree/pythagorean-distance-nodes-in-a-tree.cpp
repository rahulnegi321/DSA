class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

       
        vector<vector<int>> mpp(n, vector<int>(3, -1));
        auto getIdx = [&](int node) { return (node == x) ? 0 : (node == y ? 1 : 2); };

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{x,x}});
        q.push({0,{y,y}});
        q.push({0,{z,z}});

        while(q.size()){
            int dis = q.top().first;
            int curr = q.top().second.first;
            int from = q.top().second.second;
            q.pop();


            if(mpp[curr][getIdx(from)] != -1){
                continue;
            }
            mpp[curr][getIdx(from)] = dis;

            for(auto it : adj[curr]){
                if(mpp[it][getIdx(from)] == -1){
                    q.push({dis+1,{it,from}});
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){

            if(mpp[i][0] == -1 || mpp[i][1] == -1 || mpp[i][2] == -1) continue;

            vector<long long> temp;
            temp.push_back(mpp[i][0]);
            temp.push_back(mpp[i][1]);
            temp.push_back(mpp[i][2]);
            sort(temp.begin(),temp.end());

            long long a = temp[0];
            long long b = temp[1];
            long long c = temp[2];
            if(a*a + b*b == c*c){
                count++;
            }
        }
        return count;
    }
};