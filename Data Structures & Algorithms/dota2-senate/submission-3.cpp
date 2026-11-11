class Solution {
public:
    string predictPartyVictory(string senate) {
        int cntD = 0;
        for(int i = 0; i < senate.size(); i++) {
            if(senate.size() - i <= abs(cntD)) {
                if(senate[i] == 'R') {
                    return "Radiant";
                } else {
                    return "Dire";
                }
            }
            if(cntD == 0) {
                if(senate[i] == 'R') {
                    cntD--;
                    senate += 'R';
                } else {
                    cntD++;
                    senate += 'D';
                }
            } else if(cntD > 0) {
                if(senate[i] == 'R') {
                    cntD--;
                } else {
                    senate += 'D';
                    cntD++;
                }
            } else {
                if(senate[i] == 'R') {
                    senate += 'R';
                    cntD--;
                } else {
                    cntD++;
                }
            }
        }
        return "Hi!";
    }
};