/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        vector<int> a, b;
        while (head) {
            a.emplace_back(head->val);
            head = head->next;
        }
        b = a;
        reverse(b.begin(), b.end());
        return b == a;
    }
};