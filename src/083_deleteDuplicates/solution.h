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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        while (curr) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = prev->next;
                curr = prev->next;
            }
        }
        
        return head;
    }
};
