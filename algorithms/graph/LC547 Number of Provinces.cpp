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
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        UnionFind uf = UnionFind(n);
        int ans = n;
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                if (isConnected[row][col] == 1 && !uf.isConnected(row, col)) {
                    ans--;
                    uf.quickUnion(row, col);
                }
            }
        }
        return ans;   
    }

};

