class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3, false);
        for(int i = 0; i < triplets.size(); i++) {
            vector<bool> temp(3, false);
            bool misMatch = false;
            for(int j = 0; j < 3; j++) {
                if(triplets[i][j] > target[j]) {
                    misMatch = true;
                    break;
                }
                if(triplets[i][j] == target[j]) {
                    temp[j] = true;
                }
            }
            if(!misMatch) {
                found[0] = found[0] || temp[0];
                found[1] = found[1] || temp[1];
                found[2] = found[2] || temp[2];
            }
        }
        return found[0] && found[1] && found[2];
    }
};
