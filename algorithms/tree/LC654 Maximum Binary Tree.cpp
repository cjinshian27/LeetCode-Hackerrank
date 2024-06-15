class Solution {
    public:
        TreeNode * rec(vector<int> & nums, int i, int j){
            if(i > j){
                return nullptr;
            }
            TreeNode * t;
            int mx = INT_MIN;
            int index = 0;
            for(int k = i; k <= j; ++k){
                if(nums[k] > mx){
                    mx = nums[k];
                    index = k;
                }
            }
            t = new TreeNode(mx);
            t->left = rec(nums, i, index - 1);
            t->right = rec(nums, index + 1, j);
            
            return t;
        }

        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return rec(nums, 0, nums.size() - 1);
        }
};