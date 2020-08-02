/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if (!(A && A->next)) return A;
    ListNode* B = A->next;
    if (B == NULL) return A;
    ListNode* C = swapPairs(B->next);
    A->next = C, B->next = A;
    return B;
}
