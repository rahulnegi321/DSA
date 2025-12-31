class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    
        int n  = cells.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            set<pair<int,int>>vis;
            for(int i = 0;i<=mid;i++){
            vis.insert({cells[i][0]-1,cells[i][1]-1});
            }
            queue<pair<int,int>>q;
            for(int j = 0;j<col;j++){
                if(!vis.count({0,j})){
                    q.push({0,j});
                    vis.insert({0,j});
                }
            }
            bool poss = false;
            while(q.size()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r == row-1){
                    poss = true;
                    break;
                }
                int drow[] = {1,-1,0,0};
                int dcol[] = {0,0,-1,1};
                for(int j = 0;j<4;j++){
                    int nrow = drow[j] + r;
                    int ncol = dcol[j] + c;
                    if(nrow < row && ncol < col && nrow >= 0 && ncol >= 0 && !vis.count({nrow,ncol}) ){
                        q.push({nrow,ncol});
                        vis.insert({nrow,ncol});
                    } 
                }
            }
            if(poss){
                ans = mid;
               low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        // for(int i = 0;i<cells.size();i++){
        //     bool poss = false;
        //     st.insert({cells[i][0]-1,cells[i][1]-1});
        //     set<pair<int,int>>vis;
        //     queue<pair<int,int>>q;
        //     for(int j = 0;j<col;j++){
        //         if(!st.count({0,j})){
        //             q.push({0,j});
        //             vis.insert({0,j});
        //         }
        //     }
        //     while(q.size()){
        //         int r = q.front().first;
        //         int c = q.front().second;
        //         q.pop();
        //         if(r == row-1){
        //             poss = true;
        //             break;
        //         }
        //         int drow[] = {1,-1,0,0};
        //         int dcol[] = {0,0,-1,1};
        //         for(int j = 0;j<4;j++){
        //             int nrow = drow[j] + r;
        //             int ncol = dcol[j] + c;
        //             if(nrow < row && ncol < col && nrow >= 0 && ncol >= 0 && !vis.count({nrow,ncol}) && !st.count({nrow,ncol})){
        //                 q.push({nrow,ncol});
        //                 vis.insert({nrow,ncol});
        //             } 
        //         }
        //     }
        //     if(!poss){
        //         return i;
        //     }
        // }
        return ans+1;
    }
};