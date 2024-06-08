class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph) {
            vector<vector<int>> paths;
            vector<int> path;

            dfs(0, graph.size()-1, graph, path, paths);
            
            return paths;
        }

        void dfs(int node, int dst, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths) {

            path.push_back(node);
            
            if(node == dst){
                paths.push_back(path);
            } 
            else{
                for(int neighbor: graph[node]){
                    dfs(neighbor, graph.size()-1, graph, path, paths);
                }
            }
            
            path.pop_back();
        }
};