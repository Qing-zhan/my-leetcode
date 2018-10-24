/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int m = 0, n = 0;
        ListNode* temp = l1;
        while (temp) { m++; temp = temp->next;}
        temp = l2;
        while (temp) { n++; temp = temp->next;}
        ListNode* result = m > n ? l1 : l2;
        ListNode* curr = result;
        int carry = 0;
        while (true) {
            if (l1 || l2) {
                // watch out for the youxianji
                int temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = temp > 9 ? 1 : 0;
                curr->val = temp % 10;
                if (carry && !curr->next) curr->next = new ListNode(0);
                curr = curr->next;
            } else {
                break;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return result;
    }
};
