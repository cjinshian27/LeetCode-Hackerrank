class Solution {
    public:
        bool detectCapitalUse(string word) {
            
            int count = 0;
            
            for(int i = 0; i < word.size(); ++i){
                if(word[i] == toupper(word[i])){
                    count++;
                }
            }
            
            if(count == 0 || count == word.size() || (count == 1 && word[0] == toupper(word[0]))){
                return true;
            }
            
            return false;
        }
};