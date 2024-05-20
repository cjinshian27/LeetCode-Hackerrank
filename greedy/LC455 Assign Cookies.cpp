class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            
            sort(s.begin(), s.end());
            sort(g.begin(), g.end());

            int a = 0, b = 0;
            
            while(a < g.size() && b < s.size()){
                if(g[a] <= s[b]){
                    a++;
                }
                b++;
            }
            
            return a;
        }
};