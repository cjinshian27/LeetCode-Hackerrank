class Solution {
    public:
        int countKConstraintSubstrings(string s, int k) {
            
            int one = 0, zero = 0;
            int left = 0, right = 0;
            int ans = 0;

            while(right < s.size()){
                if(s[right] == '0'){
                    ++zero;
                }
                else{
                    ++one;
                }

                while(zero > k && one > k){
                    if(s[left] == '0'){
                        --zero;
                    }
                    else{
                        --one;
                    }
                    ++left;
                }
                ans += right - left + 1;
                right++;
            }

            return ans;
        }
};