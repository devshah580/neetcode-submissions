class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }
        
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freqs;
        for(int i = 0; i < hand.size(); i++) {
            freqs[hand[i]]++;
        }

        for(int i = 0; i < hand.size(); i++) {
            if(freqs.count(hand[i])) {
                for(int j = 0; j < groupSize; j++) {
                    if(freqs.count(hand[i] + j)) {
                        freqs[hand[i] + j]--;
                        if(freqs[hand[i] + j] == 0) {
                            freqs.erase(hand[i] + j);
                        }
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};
