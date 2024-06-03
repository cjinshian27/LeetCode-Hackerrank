class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {

            vector<int> ans;
            if(!root) return ans;
            queue<TreeNode * > q;
            q.push(root);
            
            while(!q.empty()){
                
                int s = q.size();
                int mx = INT_MIN;
                
                for(int i = 0; i < s; ++i){
                    TreeNode * aux = q.front();
                    q.pop();
                    mx = max(mx, aux->val);
                    if(aux->left){
                        q.push(aux->left);
                    }
                    if(aux->right){
                        q.push(aux->right);
                    }
                }
                ans.push_back(mx);
            } 
            return ans; 
        }
};