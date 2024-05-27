class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& score) {          
            
            int n = score.size();
            
            vector<pair<int, int>> aux(score.size());
            
            for(int i = 0; i < score.size(); ++i){
                aux[i] = {score[i], i};
            }
            
            sort(aux.rbegin(), aux.rend());
            vector<string> ranks(score.size());
            
            if(n > 0){
                ranks[aux[0].second] = "Gold Medal";
            }
            if(n > 1){
                ranks[aux[1].second] = "Silver Medal";
            }
            if(n > 2){
                ranks[aux[2].second] = "Bronze Medal";
            }

            for(int i = 3; i < n; ++i){
                ranks[aux[i].second] = to_string(i + 1); 
            }
            
            return ranks;
        }
};