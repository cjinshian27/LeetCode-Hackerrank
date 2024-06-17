/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int mx = INT_MIN;
        unordered_map<int, int> m;
        int sum(TreeNode * & root){
            
            if(!root) return 0;
            
            int left = sum(root->left);
            int right = sum(root->right);
            
            m[root->val + left + right]++;
            mx = max(mx,  m[root->val + left + right]);
            
            return root->val + left + right;
        }
        vector<int> findFrequentTreeSum(TreeNode* root) {
            
            vector<int> ans;
            sum(root);
            
            for(auto & el : m){
                if(el.second == mx){
                    ans.push_back(el.first);
                }
            }
            
            return ans;
        }
};