/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *left = NULL, *right = NULL;
    ListNode *head = A, *lhead = NULL, *rhead = NULL;
    while (head) {
        if (head->val < B) {
            if (left) left->next = head; 
            else lhead = head;
            left = head;
        } else {
            if (right) right->next = head;
            else rhead = head;
            right = head;
        }
        head = head->next;
    }
    right->next = NULL;
    if (left) left->next = rhead;
    return (lhead ? lhead : rhead);
}
