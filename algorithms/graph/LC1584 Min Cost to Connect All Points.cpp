class Solution {
    
    class UnionFind{
        vector<int> root;
        vector<int> rank;
        int size;
    
        public:
            UnionFind(int size){
                size = size;
                for(int i = 0; i < size; i++){
                    root.push_back(i);
                    rank.push_back(1);
                }      
            }
            int find(int x){
                if (x != root[x])
                    return root[x] = find(root[x]);
                return x;
            }
            bool unite(int x, int y){
                int xroot = find(x);
                int yroot = find(y);
                if (xroot != yroot) {
                    if (rank[xroot] > rank[yroot]){
                        root[yroot] = xroot;
                    }
                    else if (rank[xroot] < rank[yroot]){
                        root[xroot] = yroot;
                    }
                    else {
                        root[yroot] = xroot;
                        rank[xroot] += 1;
                    }
                    return true;
                }
                return false;
            }
    };

    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            
            int n = points.size();
            
            vector<pair<int, pair<int, int>>> allEdges;
            
            for (int currNode = 0; currNode < n; ++currNode) {
                for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
                    int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                                 abs(points[currNode][1] - points[nextNode][1]);
                    
                    allEdges.push_back({ weight, { currNode, nextNode }});
                }
            }
            
            sort(allEdges.begin(), allEdges.end());
            
            UnionFind uf(n);
            int mstCost = 0;
            int edgesUsed = 0;
            
            for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
                
                int node1 = allEdges[i].second.first;
                int node2 = allEdges[i].second.second;
                int weight = allEdges[i].first;
                
                if (uf.unite(node1, node2)) {
                    mstCost += weight;
                    edgesUsed++;
                }
            }
            
            return mstCost;
        }
        
};