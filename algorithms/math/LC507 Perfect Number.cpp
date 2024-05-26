class Solution {
    public:
        bool checkPerfectNumber(int num) {
            
            int d = sqrt(num);
            int sum = 1;
            
            if(num == 1){
                return false;
            }
            
            for(int i = 2; i <= d; ++i){
                if(num % i == 0){
                    sum += i;
                    if(num / i != i){
                        sum += num / i;
                    }
                }
            }
            
            if(sum == num) return true;
            return false;
        }
};