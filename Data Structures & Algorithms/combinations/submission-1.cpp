class Solution {
public:
    void backtrack(int n, int k, int index, vector<int>& currVec, vector<vector<int>>& result) {
        if(currVec.size() == k) {
            result.push_back(currVec);
            return;
        }

        for(int i = index; i <= n; i++) {
            currVec.push_back(i);
            backtrack(n, k, i + 1, currVec, result);
            currVec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currVec;
        backtrack(n, k, 1, currVec, result);
        return result;
    }
};