class Solution {
    public:
        bool hasAlternatingBits(int n) {
            bool b = (n & 1);
            while(n){
                int v = (n & 1);
                if(b != v) return false;
                b = !b;
                n >>= 1;
            }
            return true;
        }
};