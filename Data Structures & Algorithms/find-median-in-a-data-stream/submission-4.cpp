class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(larger.size() > 0 && larger.top() <= num) {
            larger.push(num);
        } else {
            smaller.push(num);
        }

        if(abs((int)larger.size() - (int)smaller.size()) >= 2) {
            if(larger.size() > smaller.size()) {
                int temp = larger.top();
                larger.pop();
                smaller.push(temp);
            } else {
                int temp = smaller.top();
                smaller.pop();
                larger.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(larger.size() == smaller.size()) {
            return (double)(larger.top() + smaller.top()) / 2;
        } else if(larger.size() > smaller.size()) {
            return larger.top();
        } else {
            return smaller.top();
        }
    }
};
