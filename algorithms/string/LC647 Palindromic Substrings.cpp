class Solution {
    public:
        int countSubstrings(string s) {
            int count = 0;
            for(int i = 0; i < s.size(); ++i){
                int x = i;
                int y = i;
                while(x >= 0 && y < s.size() && s[x] == s[y]){
                    x--;
                    ++y;
                    count++;
                } 
                x = i;
                y = i + 1;
                while(x >= 0 & y < s.size() && s[x] == s[y]){
                    x--;
                    ++y;
                    count++;
                }

            }
            return count;
        }
};