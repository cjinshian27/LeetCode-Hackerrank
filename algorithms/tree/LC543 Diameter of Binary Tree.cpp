class Solution {
    int mx = 0;
    public:
        int rec(TreeNode * & root){
            if(!root) return 0;
            int x = rec(root->left); 
            int y = rec(root->right);
            mx = max(mx, x + y);
            return max(x, y) + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            rec(root);
            return mx;
        }
};