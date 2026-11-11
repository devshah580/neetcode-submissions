class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "+") {
                int curr = records.top();
                int temp = curr;
                records.pop();
                curr += records.top();
                records.push(temp);
                records.push(curr);
            } else if(operations[i] == "D") {
                records.push(2 * records.top());
            } else if(operations[i] == "C") {
                records.pop();
            } else {
                records.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while(!records.empty()) {
            sum += records.top();
            records.pop();
        }
        return sum;
    }
};