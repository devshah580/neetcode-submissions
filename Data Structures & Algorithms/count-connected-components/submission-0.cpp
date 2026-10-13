class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1);
        int result = n;
        for(int i = 0; i < edges.size(); i++) {
            int parentOne = Find(parents, edges[i][0]);
            int parentTwo = Find(parents, edges[i][1]);
            if(parentTwo != parentOne) {
                parents[parentTwo] = parentOne;
                n--;
            }
        }
        return n;
    }
private:
    int Find(vector<int>& parents, int node) {
        if(parents[node] == -1) {
            return node;
        } else {
            parents[node] = Find(parents, parents[node]);
            return parents[node];
        }
    }
};
