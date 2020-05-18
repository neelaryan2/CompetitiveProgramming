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
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;
        int cnt = 0;
        while (head) head = head->next, cnt++;
        cnt = cnt / 2;
        head = tmp;
        while (cnt--) head = head->next;
        return head;
    }
};