class Solution {
    int leftLeaves = 0; 
    public:
        void rec(TreeNode * & root,  bool mark){
            
            if(root == nullptr){
                return;
            }
            if(!root->left && !root->right){
                if(mark){
                    leftLeaves += root->val;
                }
                return;
            }
            rec(root->left, 1);
            rec(root->right, 0);
        }

        int sumOfLeftLeaves(TreeNode* root) {
            
            rec(root, 0);
            return leftLeaves;
        }
};