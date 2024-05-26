class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            
            int n = nums2.size();
            stack<int> s;
            unordered_map<int, int> aux;
            
            for(int i = n - 1; i >= 0; --i){
                if(s.empty()){
                    aux[nums2[i]] = -1;
                    s.push(nums2[i]);
                }
                else{
                    while(!s.empty() && s.top() < nums2[i]){
                        s.pop();
                    }
                    if(s.empty()) aux[nums2[i]] = -1;
                    else{
                        aux[nums2[i]] = s.top();
                    }
                    s.push(nums2[i]);
                }
            }

            vector<int> result(nums1.size());

            for(int i = 0; i < nums1.size(); ++i){
                result[i] = aux[nums1[i]];
            }
            
            return result;
    }
};