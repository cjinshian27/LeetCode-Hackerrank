class Solution{
    public:
        int findMinArrowShots(vector<vector<int>>& points){
            
            sort(points.begin(), points.end());
            
            int x = points[0][1], shots = 1;
            
            for(int i = 1; i < points.size(); ++i){
                if(x >= points[i][0]){
                    x = min(points[i][1], x);
                }
                else{
                    shots++;
                    x = points[i][1];
                }
            }
            
            return shots;
        }
};