class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            
            while(stones.size() > 1){
                sort(stones.begin(), stones.end());
                int n = stones.size();
                if(stones[n-1] == stones[n-2]){
                    stones.pop_back();
                    stones.pop_back();
                }
                else{
                    int diff = stones[n-1] - stones[n-2];
                    stones.pop_back();
                    stones[n-2] = diff;
                }
            }
            if(stones.size() == 0){
                return 0;
            }
            return stones[0];
        }
};