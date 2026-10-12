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
    void reorderList(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            length++;
            curr = curr->next;
        }

        if(length <= 2) {
            return;
        }


        curr = head;
        for(int i = 0; i < (length / 2) - 1; i++) {
            curr = curr->next;
        }

        ListNode* secondHead = curr->next;
        curr->next = nullptr;

        curr = secondHead;
        ListNode* prev = nullptr;
        ListNode* next = secondHead->next;
        while(next != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        secondHead = curr;

        curr = head;
        while(curr != nullptr) {
            ListNode* temp = secondHead->next;
            secondHead->next = curr->next;
            curr->next = secondHead;
            secondHead = temp;
            
            if(curr->next->next == nullptr && secondHead != nullptr && secondHead->next == nullptr) {
                curr->next->next = secondHead;
                break;
            }
            curr = curr->next->next;
        }
    }
};
