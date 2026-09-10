class Node {
public:
    unordered_map<char, Node*> children;
    Node() {}
};

class PrefixTree {
public:
    Node* root = new Node();    
    PrefixTree() {}
    
    void insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if(curr->children.count(word[i])) {
                curr = curr->children[word[i]];
            } else {
                Node* temp = new Node();
                curr->children[word[i]] = temp;
                curr = temp;
            }
        }
        curr->children['A'] = new Node();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if(curr->children.count(word[i])) {
                curr = curr->children[word[i]];
            } else {
                return false;
            }
        }
        if(curr->children.count('A')) {
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(curr->children.count(prefix[i])) {
                curr = curr->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};
