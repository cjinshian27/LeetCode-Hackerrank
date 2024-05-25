class Solution {
    public:
        string check(int i){
            
            if(i % 3 == 0 && i % 15 == 0){
                return "FizzBuzz";
            }
            else if(i % 3 == 0){
                return "Fizz";
            }
            else if(i % 5 == 0){
                return "Buzz";
            }
            return to_string(i);
        }

        vector<string> fizzBuzz(int n) {
            
            vector<string> s(n);
            
            for(int i = 1; i <= n; ++i){
                s[i-1] = check(i);
            }
            
            return s;
        }   
};