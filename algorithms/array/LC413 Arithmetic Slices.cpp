class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            if(nums.size() < 3) return 0;
            int curr = 0;
            int ans = 0;
            for(int i = 2; i < nums.size(); ++i){
                if(nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]){
                    ++curr;
                    ans += curr;
                }
                else{
                    curr = 0;
                }
            }
            return ans;
        }
};