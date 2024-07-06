class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            bool twice = 0;
            for(int i = 1; i < nums.size(); ++i){
                if(nums[i - 1] <= nums[i]) continue;
                if(twice) return false;
                twice = true;
                if(i < 2 || nums[i - 2] <= nums[i]){
                    nums[i - 1] = nums[i];
                }
                else{
                    nums[i] = nums[i - 1];
                }
            }
            return true;
        }   
};