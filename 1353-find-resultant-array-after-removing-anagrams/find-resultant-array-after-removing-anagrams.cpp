class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 0;i<words.size()-1;i++){
            string temp = words[i];
            sort(temp.begin(),temp.end());
            if(i+1 < words.size()){
            string temp1 = words[i+1];
            sort(temp1.begin(),temp1.end());
            if(temp1 == temp){
              words.erase(words.begin()+i+1);
              i--;
            } 
            }      
        }
        return words;
    }
};