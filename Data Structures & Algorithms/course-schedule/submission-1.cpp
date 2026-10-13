class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereqs;
        vector<int> needCourses(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            prereqs[prerequisites[i][1]].push_back(prerequisites[i][0]);
            needCourses[prerequisites[i][0]]++;
        }

        queue<int> to_check;
        for(int i = 0; i < needCourses.size(); i++) {
            if(needCourses[i] == 0) {
                to_check.push(i);
            }
        }

        while(!to_check.empty()) {
            int curr = to_check.front();
            to_check.pop();
            for(int i = 0; i < prereqs[curr].size(); i++) {
                needCourses[prereqs[curr][i]]--;
                if(needCourses[prereqs[curr][i]] == 0) {
                    to_check.push(prereqs[curr][i]);
                }
            }
        }

        for(int i = 0; i < needCourses.size(); i++) {
            if(needCourses[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
