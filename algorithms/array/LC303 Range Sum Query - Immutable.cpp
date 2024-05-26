class NumArray {
    vector<int> prefixSum;
    public:
        NumArray(vector<int>& nums) {
            
            prefixSum.push_back(nums[0]);
            
            for(int i = 1; i < nums.size(); ++i){
                prefixSum.push_back(prefixSum[i-1] + nums[i]);
            }
        }
        
        int sumRange(int left, int right) {
            
            if(left > 0){
                return prefixSum[right] - prefixSum[left - 1];
            }
            
            return prefixSum[right];
        }
};

