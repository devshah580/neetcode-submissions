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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* newHead = nullptr;
        ListNode* newCurr = nullptr;

        while(curr1 != nullptr && curr2 != nullptr) {
            if(curr2->val < curr1->val) {
                ListNode* temp = new ListNode(curr2->val);
                if(newHead == nullptr) {
                    newHead = temp;
                    newCurr = temp;
                } else {
                    newCurr->next = temp;
                    newCurr = newCurr->next;
                }
                curr2 = curr2->next;
            } else {
                ListNode* temp = new ListNode(curr1->val);
                if(newHead == nullptr) {
                    newHead = temp;
                    newCurr = temp;
                } else {
                    newCurr->next = temp;
                    newCurr = newCurr->next;
                }
                curr1 = curr1->next;
            }
        }

        
        if(curr1 != nullptr) {
            if(newHead == nullptr) {
                return list1;
            } else {
                newCurr->next = curr1;
            }
        } 
        if(curr2 != nullptr) {
            if(newHead == nullptr) {
                return list2;
            } else {
                newCurr->next = curr2;
            }
        }
        return newHead;
    }
};
