class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>even1;
        unordered_map<char,int>odd1;
        unordered_map<char,int>even2;
        unordered_map<char,int>odd2;
        for(int i = 0;i<s1.size();i++){
            if(i%2 == 0){
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
            else{
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            }
        }
        return (even1==even2 && odd1 == odd2);
    }
};