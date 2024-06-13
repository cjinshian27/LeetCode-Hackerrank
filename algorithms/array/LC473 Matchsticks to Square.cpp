class Solution {
    public:
        inline bool dp(int sidesLength[], vector<int> &matches, int index, int target) {
            if (index == matches.size())
                return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
            for (int i = 0; i < 4; ++i) {
                if (sidesLength[i] + matches[index] > target) // first
                    continue;
                int j = i;
                while (--j >= 0) // third
                    if (sidesLength[i] == sidesLength[j]) 
                        break;
                if (j != -1) continue;
                sidesLength[i] += matches[index];
                if (dp(sidesLength, matches, index + 1, target))
                    return true;
                sidesLength[i] -= matches[index];
            }
            return false;
        }
        bool makesquare(vector<int>& matchsticks) {
            if(matchsticks.size() < 4){
                return false;
            }
            sort(matchsticks.begin(), matchsticks.end(), greater<int>());
            int sum = 0;
            int n = matchsticks.size(); 
            for(int i = 0; i < n; ++i){
                sum += matchsticks[i];
            }  
            if((matchsticks[0] > sum / 4) || (sum % 4 != 0)){
                return false;
            }  
            int sides[4] = {0};
            return dp(sides, matchsticks, 0, sum / 4);
        }
};