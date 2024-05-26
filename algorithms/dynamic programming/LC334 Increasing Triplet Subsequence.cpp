class Solution{
    public:
        bool increasingTriplet(vector<int>& nums){
            
            if(nums.size() < 3){
                return false;
            }
            
            int triplet1 = INT_MAX;
            int triplet2 = INT_MAX;
            
            for(int & number : nums){
                if(number < triplet1){
                    triplet1 = number; 
                }
                if(number > triplet1){
                    triplet2 = min(number, triplet2);
                }
                if(number > triplet2){
                    return true;
                }
            }
            return false;
        }
};