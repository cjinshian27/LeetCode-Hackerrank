class Solution {
    public:
        pair<int, int> rec(TreeNode * root){
            
            if(!root){
                pair<int, int> p = {0, 0};
                return p;
            }
            pair<int, int> left = rec(root->left);
            pair<int, int> right = rec(root->right);

            pair<int, int> options;
            options.first = root->val + left.second + right.second;
            options.second = max(left.first, left.second) + max(right.first, right.second);   

            return options;
        }

        int rob(TreeNode* root){
            
            pair<int, int> result = rec(root);
            return max(result.first, result.second);
        }
};