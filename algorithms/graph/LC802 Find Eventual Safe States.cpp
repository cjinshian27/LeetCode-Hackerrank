class Solution {
    public:
        int dfs(int node,vector<vector<int>> & graph, vector<bool> & visited,vector<bool> & path){
            
            visited[node] = 1;
            path[node] = 1;

            for(int & it : graph[node]){
                if(!visited[it]){
                    if(dfs(it, graph, visited, path) == true){
                        return true;
                    }
                }
                else if(path[it]){
                    return true;
                }
            }

            path[node] = 0;
            return false;
        }
        
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            
            int n = graph.size();
            vector<bool> visited(n,0);
            vector<bool> path(n,0);
            vector<int> list;
            
            for(int i = 0; i < n; ++i){
                if(!visited[i]){
                    dfs(i, graph, visited, path);
                }
            }

            for(int i = 0; i < n; ++i){
                if(!path[i]){
                    list.push_back(i);
                }
            }

            return list;
        }
};