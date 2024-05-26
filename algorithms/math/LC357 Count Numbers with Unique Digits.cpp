class Solution{
    public:
        int countNumbersWithUniqueDigits(int n){
            
            if(n == 0){
                return 1;
            }
            
            int current = 9;
            int count = 10;
            int k = 9;
            
            while(n--> 1){
                current = current * k--;
                count += current;
            }
            
            return count;
        }
};