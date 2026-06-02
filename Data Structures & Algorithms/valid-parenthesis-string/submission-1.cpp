class Solution {
public:
    bool checkValidString(string s) {
        priority_queue<int> starHeap;
        priority_queue<int> openHeap;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                starHeap.push(i);
            } else if(s[i] == '(') {
                openHeap.push(i);
            } else {
                if(openHeap.size() > 0) {
                    openHeap.pop();
                } else if(starHeap.size() > 0) {
                    starHeap.pop();
                } else {
                    return false;
                }
            }
        }

        priority_queue<int, vector<int>, greater<int>> starHeap_two;
        priority_queue<int, vector<int>, greater<int>> closeHeap;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '*') {
                starHeap_two.push(i);
            } else if(s[i] == ')') {
                closeHeap.push(i);
            } else {
                if(closeHeap.size() > 0) {
                    closeHeap.pop();
                } else if(starHeap_two.size() > 0) {
                    starHeap_two.pop();
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

//(*)(*(*)