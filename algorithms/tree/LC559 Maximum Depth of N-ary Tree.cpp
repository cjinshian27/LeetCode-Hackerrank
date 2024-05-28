class Solution {
    public:
        int rec(Node * root){
            
            if(!root) return 0;

            int mx = 0;
            for(int i = 0; i < root->children.size(); ++i){
                mx = max(mx, 1 + rec(root->children[i]));
            }

            return mx;
        }

        int maxDepth(Node* root) {
            
            if(!root) return 0;
            return rec(root) + 1;
        }
};