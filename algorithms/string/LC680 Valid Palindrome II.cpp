class Solution {
    public:
        bool validPalindrome(string s) {

            int i = 0;
            int j = s.size() - 1;
            while(i < j){
                if(s[i] != s[j]){
                    
                    bool check1 = true;
                    bool check2 = true;
                    int k = i + 1;
                    int l = j;
                    while(k < l){
                        if(s[k++] != s[l--]){
                            check1 = false;
                        }
                    }
                    k = i;
                    l = j - 1;
                    while(k < l){
                        if(s[k++] != s[l--]){
                            check2 = false;
                        }
                    }
                    return check1 || check2;
                    
                }
                ++i;
                --j;
            }
            return true;
        }
};