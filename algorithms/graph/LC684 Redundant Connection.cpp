class Solution {
    class UnionFind {
        private:
            vector<int> parents, size;
        
        public:
            UnionFind(int n){
                parents = vector<int>(n);
                size = vector<int>(n);
                for (int i = 0; i < n; i++) {
                    parents[i] = i;
                    size[i] = 1;
                }
            }
            
            int find(int p) {
                if (p == parents[p]) return p;
                return parents[p] = find(parents[p]);
            }

            bool quickUnion(int p, int q) {
                int i = find(p), j = find(q);
                if (i != j) {
                    if (size[i] < size[j]) { 
                        parents[i] = j;
                        size[j] += size[i];
                    }
                    else {
                        parents[j] = i;
                        size[i] += size[j];
                    } 
                    return true;
                }
                else return false;
            }
            
            bool isConnected(int p, int q){
                return find(p) == find(q);
            }

            vector<int>& getParents(){
                return parents;
            }
    };
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            UnionFind uf(n + 1);
            vector<int> ans;
            for(int i = 0; i < n; ++i){
                int a = edges[i][0];
                int b = edges[i][1];
                if(!uf.isConnected(a, b)){
                    uf.quickUnion(a, b);
                }
                else{
                    return {a, b};
                }
            }
            return {-1, -1};

        }
};