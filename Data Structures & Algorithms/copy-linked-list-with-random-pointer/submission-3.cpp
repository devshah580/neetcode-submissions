/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*, Node*> oldToNew;
       Node* curr = head;
       Node* newHead = nullptr;
       while(curr != nullptr) {
        Node* newNode = new Node(curr->val);
        if(curr == head) {
            newHead = newNode;
        }
        oldToNew[curr] = newNode;
        curr = curr->next;
       }

       for(auto& [key, value] : oldToNew) {
        if(key->next != nullptr) {
            value->next = oldToNew[key->next];
        }
        if(key->random != nullptr) {
            value->random = oldToNew[key->random];
        }
       }

       return newHead;
    }
};
