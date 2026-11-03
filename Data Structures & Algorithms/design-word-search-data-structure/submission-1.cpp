class Node {
public:
    char currChar;
    unordered_map<char, Node*> children;
    Node() {

    }
    Node(char newChar) {
        currChar = newChar;
    }
};

class WordDictionary {
public:
    Node* root = nullptr;
    WordDictionary() {
        root = new Node('/');
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            if(!curr->children.count(word[i])) {
                Node* temp = new Node(word[i]);
                curr->children[word[i]] = temp;
            }
            curr = curr->children[word[i]];
        }
        Node* temp = new Node('/');
        curr->children['/'] = temp;
    }

    bool searchHelper(string& word, int index, Node* curr) {
        for(int i = index; i < word.size(); i++) {
            if(word[i] == '.') {
                for(auto& [key, value] : curr->children) {
                    if(key != '/' && searchHelper(word, i + 1, value)) {
                        return true;
                    }
                }
                return false;
            } else if(!curr->children.count(word[i])) {
                return false;
            } else {
                curr = curr->children[word[i]];
            }
        }
        return curr->children.count('/');
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
