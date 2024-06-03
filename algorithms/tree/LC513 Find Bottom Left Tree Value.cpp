class Solution {
    public:
        int findBottomLeftValue(TreeNode* root) {
            
            queue<TreeNode *> q;
            q.push(root);

            int ans = root->val;
            
            while(!q.empty()){
                int s = q.size();
                for(int i = 0; i < s; ++i){
                    TreeNode * aux = q.front();
                    q.pop();
                    if(i == 0){
                        ans = aux->val;
                    }
                    if(aux->left){
                        q.push(aux->left);
                    }
                    if(aux->right){
                        q.push(aux->right);
                    }
                }
            }
            return ans;
        }
};