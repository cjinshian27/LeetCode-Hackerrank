class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            
            if(flowerbed.size() >= 2){
                if(flowerbed[0] == 0 && flowerbed[1] == 0){
                    flowerbed[0] = 1;
                    n--;
                }
                int k = flowerbed.size() - 1;
                if(flowerbed[k] == 0 && flowerbed[k - 1] == 0){
                    flowerbed[k] = 1;
                    n--;
                }
            }
            else if(flowerbed.size() == 1){
                if(flowerbed[0] == 0 || n == 0) return true;
                return false;
            }
            for(int i = 0; i < flowerbed.size(); ++i){
                if(i > 0  && i < flowerbed.size() - 1 && flowerbed[i - 1] != 1 && flowerbed[i] == 0 
                && flowerbed[i + 1] != 1){
                    flowerbed[i] = 1;
                    n--;
                }
            }

            return n <= 0;
        }
};