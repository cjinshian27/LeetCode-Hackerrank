class Solution {
    public:
        int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
            
            int dist = 0, total = 0;
            
            if(start > destination){
                swap(start, destination);
            }
            for(int i = start; i < destination; ++i){
                dist += distance[i];
            }
        
            for(int i = 0; i < distance.size(); ++i){
                total += distance[i];
            }

            return min(dist, total - dist);

        }
};