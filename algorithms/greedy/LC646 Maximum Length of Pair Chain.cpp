class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
            
            sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
            int previous = INT_MIN;
            int mx = 0;
            
            for(vector<int> & pair : pairs){
                if(pair[0] > previous){
                    ++mx;
                    previous = pair[1]; 
                }
            }
            
            return mx;
        }
};