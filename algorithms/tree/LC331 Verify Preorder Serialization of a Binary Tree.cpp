class Solution {
public:
    bool isValidSerialization(string a) {
        
        int i, degree = 1;

        for(i = 0; i < a.size(); ++i){
            
            if(--degree<0) return false;

            if(a[i] != '#'){
                degree += 2;
            }
            
            ++i;
            
            while(i<a.size() and a[i]!=','){
                i++;
            }
        }

        return degree == 0;
    }
};