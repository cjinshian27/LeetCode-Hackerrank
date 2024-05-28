class Solution {
    public:
        int distributeCandies(vector<int>& candyType) {
            
            sort(candyType.begin(), candyType.end());
            
            int count = 0;
            int n = candyType.size();
            
            for(int i = 0; i < candyType.size(); ++i){
                while(i > 0 && i < n && candyType[i] == candyType[i - 1]){
                    i++;
                }
                if(i >= n) break; 
                count++;
            }
            
            if(count > n / 2){
                return n / 2;
            }
            
            return count;
        }
};