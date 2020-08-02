/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode *head = A; int n = 0;
    while (head) head = head->next, n++;
    int k = 1 + (n - 1) / 2; head = A;
    while (k--) head = head->next;
    ListNode *prv = NULL, *nxt, *nhead = A;
    for (int i = 0; i < n / 2; i++) {
        nxt = head->next;
        head->next = prv;
        prv = head;
        head = nxt;
    }
    head = prv;
    for (int i = 0; i < n / 2; i++) {
        if (head->val != nhead->val) return 0;
        head = head->next;
        nhead = nhead->next;
    }
    return 1;
}
