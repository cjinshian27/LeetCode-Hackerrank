// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            
            int l = 0, h = n, ans = 0;
            
            while(l <= h){
                int mid= l + (h - l) / 2;
                
                if(isBadVersion(mid)) {
                    ans = mid;
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            
            return ans;
        }
};