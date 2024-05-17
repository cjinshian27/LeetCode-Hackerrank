class Solution {
    public:
        char findTheDifference(string s, string t) {
            
            vector<int> chars(27, 0);
            
            for(char & c : t){
                chars[c - 'a']++;
            } 
            
            for(char & c : s){
                chars[c - 'a']--;
            }
            
            int i = 0;
            
            for(; i < 27; ++i){
                if(chars[i]) break; 
            }
            
            return char(i) + 'a';
        }
};