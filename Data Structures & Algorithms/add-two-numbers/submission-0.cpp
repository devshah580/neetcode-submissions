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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* sumList = nullptr;
        ListNode* head = nullptr;
        int carryOver = 0;
        while(curr1 != nullptr || curr2 != nullptr) {
            int sum = carryOver;
            if(curr1 != nullptr) {
                sum += curr1->val;
                curr1 = curr1->next;
            }
            if(curr2 != nullptr) {
                sum += curr2->val;
                curr2 = curr2->next;
            }
            
            ListNode* newNode = new ListNode(sum % 10);
            if(sumList == nullptr) {
                head = sumList = newNode;
            } else {
                sumList->next = newNode;
                sumList = sumList->next;
            }
            carryOver = sum / 10;
        }
        if(carryOver != 0) {
            ListNode* newNode = new ListNode(carryOver);
            sumList->next = newNode;
        }
        return head;
    }
};
