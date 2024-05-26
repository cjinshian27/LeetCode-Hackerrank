class Solution {
    public:
        bool vowel(char c){
            
            switch(c){
                case 'a': return true;
                case 'e': return true;
                case 'i': return true;
                case 'o': return true;
                case 'u': return true;
                default: return false; 
            }
        }
        string reverseVowels(string s) {
            
            int i = 0;
            int j = s.size() - 1;
            
            while(i < j){
                while(!vowel(tolower(s[i])) && i < j){
                    i++;
                }
                while(!vowel(tolower(s[j])) && i < j){
                    j--;
                }
                swap(s[i++], s[j--]);
            }
            
            return s;
        }
};