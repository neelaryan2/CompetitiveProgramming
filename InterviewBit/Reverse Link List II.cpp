/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *left = A, *right = A, *prv = NULL, *nxt;
    while (--B) prv = left, left = left->next;
    while (--C) right = right->next;
    if (prv) prv->next = right;
    else A = right;
    ListNode *last = right->next;
    prv = right->next;
    while (left != last) {
        nxt = left->next;
        left->next = prv;
        prv = left;
        left = nxt;
    }
    return A;
}
