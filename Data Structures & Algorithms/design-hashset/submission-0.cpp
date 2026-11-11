class MyHashSet {
private:
    vector<bool> seen;
public:
    MyHashSet() {
        seen.resize(1000001);
    }
    
    void add(int key) {
        seen[key] = true;
    }
    
    void remove(int key) {
        seen[key] = false;
    }
    
    bool contains(int key) {
        return seen[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */