class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> times;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(times.count(key)) {
            times[key].push_back({value, timestamp});
        } else {
            times[key] = {{value, timestamp}};
        }
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& currVec = times[key];
        int left = 0;
        int right = currVec.size() - 1;
        int result = -1;
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(timestamp < currVec[middle].second) {
                right = middle - 1;
            } else {
                result = max(result, middle);
                left = middle + 1;
            }
        }
        if(result == -1) {
            return "";
        } else {
            return currVec[result].first;
        }
    }
};
