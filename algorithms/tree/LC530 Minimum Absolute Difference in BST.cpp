class Solution {
    int diff = 100000;
    public:

    void rec(TreeNode* root, int & previous){
        if(!root) return;
        
        rec(root->left, previous);
        diff = min(diff, abs(root->val - previous));
        previous = root->val;
        rec(root->right, previous);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int x = 100000;
        rec(root, x);
        return diff;
    }
};