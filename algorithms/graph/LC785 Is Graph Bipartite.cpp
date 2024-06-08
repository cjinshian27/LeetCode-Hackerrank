class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            
            queue<int> q;

            int color[101] = {-1};
            
            for(int i = 0; i < graph.size(); ++i){
                color[i] = -1;
            }

            for(int i = 0; i < graph.size(); ++i){
                
                if(color[i] < 0){
                    
                    color[i] = 0;
                    q.push(i);

                    while(!q.empty()){  
                        
                        int u = q.front();
                        q.pop();

                        for(int i = 0; i < graph[u].size(); ++i){

                            if(color[graph[u][i]] < 0){
                                color[graph[u][i]] = !color[u];
                                q.push(graph[u][i]);
                            }
                            else if(color[graph[u][i]] == color[u]){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
};