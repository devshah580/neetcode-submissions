class Solution {
public:
//
//0-->1
//1-->0, 2, 3, 4
//2-->1, 3
//3-->2, 1
//4-->1

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> neighbors;
        for(int i = 0; i < edges.size(); i++) {
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> seen;
        unordered_set<int> allTimeSeen;
        return helper(0, -1, neighbors, seen, allTimeSeen) && allTimeSeen.size() == n;
    }

    bool helper(int curr, int prev, unordered_map<int, vector<int>>& neighbors, 
                unordered_set<int>& seen, unordered_set<int>& allTimeSeen) {
        
        allTimeSeen.insert(curr);
        if(seen.count(curr)) {
            return false;
        }

        seen.insert(curr);
        for(int i = 0; i < neighbors[curr].size(); i++) {
            if(neighbors[curr][i] != prev) {
                if(!helper(neighbors[curr][i], curr, neighbors, seen, allTimeSeen)) {
                    return false;
                }
            }
        }
        seen.erase(curr);

        return true;
    }
};
