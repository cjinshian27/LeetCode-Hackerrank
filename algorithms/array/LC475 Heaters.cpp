class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            
            sort(houses.begin(), houses.end());
            sort(heaters.begin(), heaters.end());
            
            int left, right;
            
            int j = 0;
            
            int radius = 0;
            
            for(int i = 0; i < houses.size(); ++i){
                while(j < heaters.size() - 1 && heaters[j] <= houses[i]){
                    ++j;
                }
                left = abs(houses[i] - (j > 0 ? heaters[j - 1] : heaters[0]));
                right = abs(heaters[j] - houses[i]);

                radius = max(radius, min(right, left));

            }
            
            return radius;
        }
};