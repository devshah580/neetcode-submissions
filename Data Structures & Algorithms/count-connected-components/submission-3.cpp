class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1);
        vector<int> rank(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            int parentOne = Find(parents, edges[i][0]);
            int parentTwo = Find(parents, edges[i][1]);
            if(parentTwo != parentOne) {
                if(rank[parentOne] < rank[parentTwo]) {
                    parents[parentOne] = parentTwo;
                } else if(rank[parentOne] > rank[parentTwo]) {
                    parents[parentTwo] = parentOne;
                } else {
                    parents[parentTwo] = parentOne;
                    rank[parentOne]++;
                }
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
