/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *head = A, *prv = NULL;
    while (head && head->next) {
        int cnt = 0;
        while (head && head->next && head->val == head->next->val)
            head->next = head->next->next, cnt++;
        if (cnt) {
            if (prv) prv->next = head->next;
            else A = head->next;
        } else prv = head;
        head = head->next;
    }
    return A;
}
