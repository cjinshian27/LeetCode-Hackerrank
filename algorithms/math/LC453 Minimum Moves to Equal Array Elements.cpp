class Solution{
    public:
        int minMoves(vector<int>& nums){
            
            int smallest = INT_MAX, moves = 0;
            
            for(int i = 0; i < nums.size(); ++i){
                smallest = min(smallest, nums[i]);
            }
            
            for(int i = 0; i < nums.size(); ++i){
                moves += nums[i] - smallest;
            }

            return moves;
        }
};