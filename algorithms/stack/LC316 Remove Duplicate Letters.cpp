class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[27] = {0};
        for(char & c : s){
            ++count[c - 'a'];
        }

        stack<char> st;

        bool contain[27] = {0};

        for(int i = 0; i < s.size(); ++i){
            
            --count[s[i] - 'a'];
            if(contain[s[i] - 'a']){
                continue;
            }
            else{
                while(!st.empty() && st.top() > s[i] && count[st.top() - 'a'] > 0) {
                    contain[st.top() - 'a'] = 0;
                    st.pop();
                }
                if(!contain[s[i] - 'a']){
                    st.push(s[i]);
                    contain[s[i] - 'a'] = 1;
                }
            
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};