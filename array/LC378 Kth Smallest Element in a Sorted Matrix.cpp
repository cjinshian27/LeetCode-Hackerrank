class Solution{
	public:
	    int count(vector<vector<int>>& matrix, int mid){
	        int n = matrix.size();
	        int row = 0; 
	        int column = n - 1;
	        int count = 0;
	        while(row < n && column >= 0){
	            if(matrix[row][column] <= mid){
	                count += column + 1;
	                row++; 
	            }
	            else{
	                column--;
	            }
	        }
	        return count;
	    }
	    int kthSmallest(vector<vector<int>>& matrix, int k){
	        int n = matrix.size();

	        int low = matrix[0][0], high = matrix[n - 1][n - 1];
	        while(low < high){
	            int mid = low + (high - low) / 2;
	            int c = count(matrix, mid);

	            if(c < k){
	                low = mid + 1;
	            }
	            else{
	                high = mid;
	            }
	        }
	        return high;
	    }
};