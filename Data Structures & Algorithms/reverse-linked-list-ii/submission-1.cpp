/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        if(left != 1) {
            prev = head;
            for(int i = 1; i < left - 1; i++) {
                prev = prev->next;
            }
        }
        ListNode* curr = nullptr;
        if(prev != nullptr) {
            curr = prev->next;
        } else {
            curr = head;
        }
        ListNode* storeCurr = curr;
        ListNode* storePrev = prev;
        ListNode* next = nullptr;
        for(int i = 0; i <= (right - left); i++) {
            next = curr->next;
                        if(prev != nullptr) {
                cout << "prev: " << prev->val << endl;  
            }

            if(curr != nullptr) {
                cout << "curr: " << curr->val << endl;
            }

            if(next != nullptr) {
                cout << "next: " << next->val << endl;
            }
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        storeCurr->next = curr;
        if(storePrev != nullptr) {
            storePrev->next = prev;
        }
        if(left == 1) {
            return prev;
        } else {
            return head;
        }
    }
};