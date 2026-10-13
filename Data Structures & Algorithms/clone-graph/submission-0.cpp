/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> to_check;
        to_check.push(node);
        oldToNew[node] = new Node(node->val);
        Node* returnNode = oldToNew[node];
        while(!to_check.empty()) {
            Node* curr = to_check.front();
            to_check.pop();
            vector<Node*>& neighs = curr->neighbors;
            for(int i = 0; i < neighs.size(); i++) {
                if(!oldToNew.count(neighs[i])) {
                    oldToNew[neighs[i]] = new Node(neighs[i]->val);
                    to_check.push(neighs[i]);
                }
            }
        }

        for(const auto& [key, value] : oldToNew) {
            vector<Node*>& keyNeighs = key->neighbors;
            vector<Node*>& valueNeighs = value->neighbors;
            for(int i = 0; i < keyNeighs.size(); i++) {
                valueNeighs.push_back(oldToNew[keyNeighs[i]]);
            }
        }
        return returnNode;
       
    }
};
