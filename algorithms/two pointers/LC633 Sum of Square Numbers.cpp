class Solution {
    public:
        bool judgeSquareSum(int c) {
            long long int j = sqrt(c);
            long long int i = 0;
            while(i <= j){
                long long int t = i * i + j * j;
                if(t == c){
                    return true;
                }
                else if(t < c){
                    i++;
                }
                else{
                    j--;
                }
            }
            return false;

        }
};