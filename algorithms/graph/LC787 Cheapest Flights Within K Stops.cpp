class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            
            vector<vector<pair<int, int>>> adj(flights.size() + 1);
            for(int i = 0; i < flights.size(); ++i){
                int u = flights[i][0];
                int v = flights[i][1];
                int c = flights[i][2];
                adj[u].push_back({v, c});
            }

            queue<pair<int, int>> q;
            
            int prices[101];

            for(int i = 0; i < 101; ++i){
                prices[i] = INT_MAX;
            }
            prices[src] = 0;
            q.push({src, 0});

            while(!q.empty() && k >= 0){
                int s = q.size();
                for(int j = 0; j < s; ++j){
                    pair<int, int> p = q.front();
                    q.pop();
                    int node = p.first;
                    int price = p.second;
                    
                    for(pair<int, int> & neighbor : adj[node]){
                        if(prices[neighbor.first] > neighbor.second + price){
                            prices[neighbor.first] = neighbor.second + price;
                            q.push({neighbor.first, prices[neighbor.first]});
                        }
                    }
                } 
                k--;  
            }


            if(prices[dst] == INT_MAX) return -1;
            return prices[dst];
        }
};