class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preqs;
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];

            preqs[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> eligible_courses;
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) {
                eligible_courses.push(i);
            }
        }

        vector<int> result;
        while(!eligible_courses.empty()) {
            int curr = eligible_courses.front();
            eligible_courses.pop();
            result.push_back(curr);
            for(int i = 0; i < preqs[curr].size(); i++) {
                indegree[preqs[curr][i]]--;
                if(indegree[preqs[curr][i]] == 0) {
                    eligible_courses.push(preqs[curr][i]);
                }
            }
        }

        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] != 0) {
                return {};
            }
        }
        return result;
    }
};
