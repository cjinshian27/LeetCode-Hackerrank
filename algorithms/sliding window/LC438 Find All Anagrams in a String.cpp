class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            
            vector<int> ans;
            if(s.size() < p.size()){
                return ans;
            }
            vector<int> a(26,0);
            vector<int> b(26,0);
            for(char & c : p){
                b[c - 'a']++;
            }

            int i = 0, j = 0;

            while(j < s.size()){
                a[s[j] - 'a']++;

                if(j - i + 1 == p.size()){
                    if(a == b){
                        ans.push_back(i);
                    }
                }
                if(p.size() > j - i + 1){
                    j++;
                }
                else{
                    a[s[i] - 'a']--;
                    i++;
                    j++;
                }            
            }
            return ans;
        }
};