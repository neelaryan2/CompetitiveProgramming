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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val > l2->val) {
            auto head = mergeTwoLists(l1, l2->next);
            l2->next = head;
            return l2;
        } else {
            auto head = mergeTwoLists(l1->next, l2);
            l1->next = head;
            return l1;
        }
    }
};