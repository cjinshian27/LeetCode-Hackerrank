class Solution {
    public:
        int binaryGap(int n) {
            int dist = 0;

            while((n & 1) != 1){   
                n >>= 1;
            }
            int curr = 0;
            while(n){   
                if((n & 1) == 1){
                    dist = max(dist, curr);
                    curr = 0;
                }
                curr++;
                n >>= 1;
            }
            return dist;
        }
};