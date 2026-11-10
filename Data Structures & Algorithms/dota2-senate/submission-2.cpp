class Solution {
public:
    string predictPartyVictory(string senate) {
        int i = 0;
        while(true) {
            if(senate[i] == 'R') {
                int curr = (i + 1) % senate.size();
                while(curr != i && senate[curr] != 'D') {
                    curr = (curr + 1) % senate.size();
                }
                if(curr == i) {
                    return "Radiant";
                } else {
                    senate[curr] = '0';
                }
            } else if(senate[i] == 'D') {
                int curr = (i + 1) % senate.size();
                while(curr != i && senate[curr] != 'R') {
                    curr = (curr + 1) % senate.size();
                }
                if(curr == i) {
                    return "Dire";
                } else {
                    senate[curr] = '0';
                }
            }
            i = (i + 1) % senate.size();
        }
        return "Hi!!!!!";
    }
};