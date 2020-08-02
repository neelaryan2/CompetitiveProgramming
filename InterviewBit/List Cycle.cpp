/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* cycle(ListNode* list) { 
    ListNode *slow = list, *fast = list; 
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast)
            return slow; 
    } 
    return NULL; 
}
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* B = cycle(A);
    if (B == NULL) return B;
    while (A != B) A = A->next, B = B->next;
    return A;
}
