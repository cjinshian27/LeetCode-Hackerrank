class Codec {
    public:
        string serialize(TreeNode* root) {
            if(!root) return "";
            
            queue<TreeNode *> q;
            q.push(root);
            
            string s = "";
            
            while(!q.empty()){
                TreeNode * curr = q.front();
                q.pop();
                if(curr == nullptr){
                    s.append("#,");
                }
                else{
                    s.append(to_string(curr->val) + ',');
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            
            if(data == "") return nullptr;
            
            stringstream s(data);
            string str;
            
            getline(s, str, ',');
            
            TreeNode * root = new TreeNode(stoi(str));
            queue<TreeNode * > q;
            q.push(root);
            
            while(!q.empty()){
                TreeNode * node = q.front();
                q.pop();
                getline(s, str, ',');
                if(str == "#"){
                    node->left = nullptr;
                }
                else{
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }

                getline(s, str, ',');
                if(str == "#"){
                    node->right = nullptr;
                }
                else{
                    node->right =  new TreeNode(stoi(str));
                    q.push(node->right); 
                }
            }
            return root;
        }
};
