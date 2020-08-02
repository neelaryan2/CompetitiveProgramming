/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *head = A, *newhead = NULL, *prv_last = NULL;
    while (head) {
        int cur = B;
        ListNode *start = head, *prv = NULL, *nxt;
        while (cur--) {
            nxt = start->next;
            start->next = prv;
            prv = start;
            start = nxt;
        }
        if (newhead == NULL) newhead = prv;
        else prv_last->next = prv;
        prv_last = head;
        head = start;
    }
    return newhead;
}
