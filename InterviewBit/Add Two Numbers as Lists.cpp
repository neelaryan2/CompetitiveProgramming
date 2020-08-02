/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int s = 0; ListNode *ha = A, *hb = B;
    if (ha) s += ha->val, ha = ha->next;
    if (hb) s += hb->val, hb = hb->next;
    ListNode *res = new ListNode(s % 10);
    ListNode *hc = res, *nonzero = res;
    while (ha != NULL || hb != NULL || s) {
        s /= 10;
        if (ha) s += ha->val, ha = ha->next;
        if (hb) s += hb->val, hb = hb->next;
        hc->next = new ListNode(s % 10);
        hc = hc->next;
        if (hc->val) nonzero = hc;
    }
    nonzero->next = NULL;
    return res;
}
