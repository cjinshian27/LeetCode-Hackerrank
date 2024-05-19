class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int i = 0, j = 0, result = 0;
            
            while(j < nums.size()){
                if(nums[j] == 0){
                    result = max(result, j - i);
                    j++;
                    i = j;
                }
                else{
                    j++;
                }
            }
            
            result = max(result, j - i);
            return result;
        }
};