class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1, -1);
        //-1, -1, -1, -1, -1, -1
        vector<int> result;
        for(int i = 0; i < edges.size(); i++) {
            int parentOne = Find(parents, edges[i][0]); //1
            int parentTwo = Find(parents, edges[i][1]); //2
            if(parentTwo != parentOne) {
                parents[parentTwo] = parentOne;
            } else {
                result = edges[i];
            }
        }
        return result;
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
