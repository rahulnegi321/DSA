class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char curr = '.';
        for(int i = 0;i<letters.size();i++){
            if(letters[i] > target){
                if(curr == '.'){
                    curr = letters[i];
                }
                else{
                    curr = min(curr,letters[i]);
                }
            }
        }
        return curr == '.'? letters[0] : curr;
    }
};