class Solution {
    public:
        unordered_map<int,int> mp;
        
        int dp[2001][2001];

        int helper(int curr_stone_idx, int prevJump, vector<int>& stones){
            
            if(curr_stone_idx == stones.size() - 1){ 
                return true;
            }

            if(dp[curr_stone_idx][prevJump] != -1){
                return dp[curr_stone_idx][prevJump];
            }

            bool result = false;

            for(int nextJump = prevJump - 1; nextJump <= prevJump+1; nextJump++){

                if(nextJump > 0){ 
                    
                    int nextStone = stones[curr_stone_idx] + nextJump;

                    if(mp.find(nextStone) != mp.end()){ 
                        result |= helper(mp[nextStone], nextJump, stones);
                    }
                }
            }

            return dp[curr_stone_idx][prevJump] = result;
        }

        bool canCross(vector<int>& stones) {

            if(stones[1] != 1){ 
               return false;
            }

            for(int i = 0; i < stones.size(); ++i){ 
                mp[stones[i]] = i;
            }

            memset(dp,-1,sizeof(dp));

            return helper(0, 0, stones);
        }
};