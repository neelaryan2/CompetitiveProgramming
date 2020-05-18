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
    pair<ListNode*, ListNode*> aux(ListNode* head) {
        if (head->next == NULL) return make_pair(head, head);
        auto tmp = aux(head->next);
        tmp.second->next = head;
        head->next = NULL;
        return make_pair(tmp.first, head);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        pair<ListNode*, ListNode*> ans = aux(head);
        return ans.first;
    }
};