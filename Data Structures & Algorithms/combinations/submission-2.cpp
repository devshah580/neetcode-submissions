class Solution {
public:
    void backtrack(int n, int k, int index, vector<int>& currVec, vector<vector<int>>& result) {
        if(currVec.size() == k) {
            result.push_back(currVec);
            return;
        }

        if(index > n) {
            return;
        }

        currVec.push_back(index);
        backtrack(n, k, index + 1, currVec, result);
        currVec.pop_back();
        backtrack(n, k, index + 1, currVec, result);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currVec;
        backtrack(n, k, 1, currVec, result);
        return result;
    }
};