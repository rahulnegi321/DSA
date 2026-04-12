class Solution {
public:
    map<tuple<char,char,int>,int>dp;
    map<char,pair<int,int>>location;
    int helper(int ind,char left,char right,string& word){
        if(ind >= word.size()-1){
            return 0;
        }
        auto it = make_tuple(left,right,ind);
        if(dp.count(it)){
            return dp[it];
        }
        int take_right = INT_MAX;
        int take_left  = abs(location[left].first-location[word[ind+1]].first) + abs(location[left].second - location[word[ind+1]].second) + helper(ind+1,word[ind+1],right,word);

        if(right == 'n'){
            take_right = helper(ind+1,left,word[ind+1],word);
        }
        else{
            take_right  = abs(location[right].first-location[word[ind+1]].first) + abs(location[right].second - location[word[ind+1]].second) + helper(ind+1,left,word[ind+1],word);
        }
        return dp[it] = min(take_left,take_right);
    }
    int minimumDistance(string word) {
      char start = 'A';
      for(int i = 0;i<5;i++){
        for(int j = 0;j<6;j++){
           location[start] = {i,j};
            if(start == 'Z'){
            break;
           }
           start++;
        }
      }
      return helper(0,word[0],'n',word);
    }
};