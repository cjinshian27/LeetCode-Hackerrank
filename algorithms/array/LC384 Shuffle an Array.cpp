class Solution {
    public:
        vector<int> v, original;
        
        Solution(vector<int> & nums){
            
            v = nums;
            
            original = nums;
        }
        
        vector<int> reset(){
            
            return original;
        }
        
        vector<int> shuffle(){
            
            next_permutation(begin(v),end(v));
            
            return v;
        }
};