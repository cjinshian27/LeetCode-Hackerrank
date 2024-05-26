class Solution {
    public:
        vector<int> constructRectangle(int area) {
        
            int n = sqrt(area);
        
            if(n * n == area) return {n, n};
            
            for(int i = n; i > 0; --i){
                if((i) * (area / i) == area){
                    return {area / i, i};
                }
            }
            
            return {};
        }
};