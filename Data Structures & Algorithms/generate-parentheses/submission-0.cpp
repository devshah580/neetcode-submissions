class Solution {
public:
    void dfs(int n, int open, string& curr, vector<string>& result) {
        if(curr.size() == (2 * n)) {
            result.push_back(curr);
            return;
        }

        if(curr.size() - open < open) {
            curr += ')';
            dfs(n, open, curr, result);
            curr.pop_back();
        }

        if(open < n) {
            curr += '(';
            dfs(n, open + 1, curr, result);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        dfs(n, 0, curr, result);
        return result;
    }
};
