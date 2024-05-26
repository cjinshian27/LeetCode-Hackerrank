class Solution {
    public:
        int currentVal = 0;
        int currentCount = 0;
        int maxCount = 0;
        std::vector<int> modes; 

        inline void rec(TreeNode* node) {
            if (!node) return;
            
            rec(node->left);
            
            currentCount = (node->val == currentVal) ? currentCount + 1 : 1;
            if (currentCount == maxCount) {
                modes.push_back(node->val);
            } else if (currentCount > maxCount) {
                maxCount = currentCount;
                modes = { node->val };
            }
            currentVal = node->val;

            rec(node->right);
        }

        std::vector<int> findMode(TreeNode* root) {
            rec(root);
            return modes;
        }
};