class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            int n = nums.size();
            int count = 0;
            int i, j;
            
            for(int k = nums.size() - 1; k >= 0; --k){
                j = k - 1;
                i = 0; 
                while(i < j){
                    if(nums[i] + nums[j] > nums[k]){
                        count += j - i;
                        j--;
                    }
                    else{
                        i++;
                    }
                }
            }
            return count;
        }
};