/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int k) {
    int n = 1; ListNode* head = A;
    while (head->next) head = head->next, n++;
    ListNode* last = head;
    k = n - 1 - k % n; head = A;
    while (k--) head = head->next;
    last->next = A;
    A = head->next;
    head->next = NULL;
    return A;
}
