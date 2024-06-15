class Solution {
    public:
        int distance(vector<int> & p1, vector<int> & p2){
            int x = (p1[0] - p2[0]) * (p1[0] - p2[0]);
            int y = (p1[1] - p2[1]) * (p1[1] - p2[1]);
            return sqrt(x + y);
        }

        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            vector<int> arr[4] = {p1, p2, p3, p4};
            sort(arr, arr + 4);
            
            for(int i = 1; i < 4; ++i){
                if(arr[i] == arr[i - 1]) return false;
            }

            int dist1 = distance(arr[0], arr[1]);
            int dist2 = distance(arr[1], arr[3]);
            int dist3 = distance(arr[3], arr[2]);
            int dist4 = distance(arr[0], arr[2]);
            int dist5 = distance(arr[2], arr[1]);
            int dist6 = distance(arr[0], arr[3]);
            return dist1 == dist2 && dist2 == dist3 && dist3 == dist4 && dist5 == dist6;
        }
};