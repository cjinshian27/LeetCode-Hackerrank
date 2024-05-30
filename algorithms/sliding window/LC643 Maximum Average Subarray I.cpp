class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
           
            int i = 0, j = 0;
            int mx = INT_MIN;
            int val = nums[0];
            while(j < nums.size()){
                
                if(j - i + 1 < k){
                    j++;
                    val += nums[j];
                }
                else{
                    break;
                }
            }
            while(j < nums.size()){
                if(mx < val){
                    mx = val;
                } 

                val -= nums[i++];
                ++j;
                if(j >= nums.size()) break;
                val += nums[j];
            
            }
            return (double) mx / (double) k;
        }
};