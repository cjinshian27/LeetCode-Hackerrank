class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            
            vector<int> letters1(27, 0);
            vector<int> letters2(27, 0);
            
            for(int i = 0; i < ransomNote.size(); ++i){
                letters1[ransomNote[i] - 'a']++;
            }
            
            for(int i = 0; i < magazine.size(); ++i){
                letters2[magazine[i] - 'a']++;
            }   
            
            for(int i = 0; i < ransomNote.size(); ++i){
                if(letters1[ransomNote[i] - 'a'] > letters2[ransomNote[i] - 'a']) return false;
            }
            
            return true;
        }
};