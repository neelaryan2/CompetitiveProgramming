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
    ListNode* removeNthFromEnd(ListNode* head, int m) {
        ListNode* cpy = head;
        int n = 0;
        while (cpy) cpy = cpy->next, n++;
        cpy = head;
        n = n - m;
        if (n == -1) return head;
        if (n == 0) return head->next;
        while (--n && cpy) cpy = cpy->next;
        if (cpy->next) cpy->next = cpy->next->next;
        return head;
    }
};