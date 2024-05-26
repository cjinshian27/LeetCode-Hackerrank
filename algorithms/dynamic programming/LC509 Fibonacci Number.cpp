class Solution {
    public:
        int fib(int n) {
            
            if(!n) return 0;
            
            int p = 0;
            int pp = 1;
            int nth = 1;
            
            for(int i = 1; i <= n; ++i){
                nth = p + pp;
                pp = p;
                p = nth;
            }
            return nth;
        }
};