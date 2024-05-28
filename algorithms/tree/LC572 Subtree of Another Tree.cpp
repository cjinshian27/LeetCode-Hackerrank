class Solution {
    public:
        bool isSameTree(TreeNode* root, TreeNode* subRoot){
            
            if(!subRoot && !root)
                return true;
            else if(!subRoot && root)
                return false;
            else if(subRoot && !root)
                return false;
            else if(root->val != subRoot->val)
                return false;
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        }

        bool isSubtree(TreeNode* root, TreeNode* subRoot) {

            if(!subRoot)
                return true;
            if(!root)
                return false;
            if(isSameTree(root, subRoot))
                return true;
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
};