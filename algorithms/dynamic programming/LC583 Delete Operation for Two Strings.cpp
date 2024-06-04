class Solution {
    public:
        int lcs(string & s1, string & s2){
            
            int n = s1.size();
            int m = s2.size();
            
            vector<int> previous(m + 1, 0), curr(m + 1, 0);
            
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    if(s1[i - 1] == s2[j - 1]){
                        curr[j] = 1 + previous[j - 1];
                    }
                    else{
                        curr[j] = max(previous[j], curr[j - 1]);
                    }
                }
                previous = curr;
            }
            return previous[m];
        }

        int minDistance(string & word1, string & word2) {
            
            int l = lcs(word1, word2);
            return word1.size() + word2.size() - l - l; 
        }
};