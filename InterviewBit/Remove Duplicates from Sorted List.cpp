/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *head = A;
    while (head && head->next) {
        if (head->val != head->next->val)
            head = head->next;
        else 
            head->next = head->next->next;
    }
    return A;
}
