class Solution {
public:
    int partitionString(string s) {
      int count  = 0;
      string temp = "";
      unordered_map<char,int>mpp;
      for(int i = 0;i<s.size();i++){
        if(mpp[s[i]] == 1){
            count++;
            mpp.clear();
            mpp[s[i]]++;
        }
        else{
            mpp[s[i]]++;
        }
      }
      return count+1;  
    }
};