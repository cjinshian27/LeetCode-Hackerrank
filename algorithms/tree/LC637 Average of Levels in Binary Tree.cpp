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
    vector<double> ans;
    
    public:
        vector<double> averageOfLevels(TreeNode* root) {
            queue<TreeNode *> q;
            q.push(root);


            while(!q.empty()){
                int s = q.size();
                long long int sum = 0;
                for(int i = 0; i < s; ++i){
                    TreeNode * aux = q.front();
                    sum += aux->val;
                    q.pop();
            
                    if(aux->left) q.push(aux->left);
                    if(aux->right) q.push(aux->right);
                }
                ans.push_back(double(sum) / s);
            }
            return ans;
         }
};