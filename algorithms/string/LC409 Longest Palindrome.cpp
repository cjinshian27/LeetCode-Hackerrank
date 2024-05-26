class Solution{
    public:
        int longestPalindrome(string s){
            
            vector<int> count1(27, 0);
            vector<int> count2(27, 0);
            
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == tolower(s[i])){
                    count1[s[i] - 'a']++;
                }
                else{
                    count2[s[i] - 'A']++;
                }
            }
            
            int longest = 0;
            bool odd = 0;
            
            for(int i = 0; i < 27; ++i){
                if(count1[i] % 2 != 0 || count2[i] % 2 != 0){
                    odd = 1;
                }
                longest += (count1[i] % 2 == 0) ? count1[i] : count1[i] - 1;
                longest += (count2[i] % 2 == 0) ? count2[i] : count2[i] - 1;
            }
            
            if(odd){
                return longest + 1;
            }

            return longest;     
        }
};