class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            
            queue<int> q;
       
            q.push(0);
            char visited[1000] = {0};
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                visited[node] = true;
                for(int i = 0; i < rooms[node].size(); ++i){
                    if(!visited[rooms[node][i]]){
                        q.push(rooms[node][i]);
                        visited[rooms[node][i]] = true;
                    }
                }
            }

            int n = rooms.size();
            for(int i = 0; i < n; ++i){
                if(!visited[i]){
                    return false;
                }
            }
            return true;
        }
};