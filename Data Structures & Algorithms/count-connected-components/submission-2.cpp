class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1);
        for(int i = 0; i < edges.size(); i++) {
            pair<int, int> parentOne = Find(parents, edges[i][0]);
            pair<int, int> parentTwo = Find(parents, edges[i][1]);
            if(parentTwo.first != parentOne.first) {
                if(parentTwo.second < parentOne.second) { 
                    parents[parentTwo.first] = parentOne.first;
                } else {
                    parents[parentOne.first] = parentTwo.first;
                }
                n--;
            }
        }
        return n;
    }
private:
    pair<int, int> Find(vector<int>& parents, int node) {
        if(parents[node] == -1) {
            return {node, 0};
        } else {
            pair<int, int> findResult = Find(parents, parents[node]);
            parents[node] = findResult.first;
            return {parents[node], findResult.second + 1};
        }
    }
};
