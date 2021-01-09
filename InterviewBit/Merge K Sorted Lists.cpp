/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode *head = NULL, *ret = NULL;
    while(1) {
        ListNode* mn = NULL;
        for (auto h : A) {
            if (!h) continue;
            if (!mn || mn->val > h->val) 
                mn = h;
        }
        if (head) head->next = mn;
        else ret = mn;
        if (!mn) break;
        for (int i = 0; i < A.size(); i++) {
            auto& h = A[i];
            if (!h) continue;
            if (mn->val == h->val) {
                 h = h->next;
                 if (!h) A.erase(A.begin() + i);
                 break;
            }
        }
        head = mn;
    }
    return ret;
}
