/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* aux(int s, int e, vector<int>& a) {
        if (s >= e) return NULL;
        int m = (s + e) / 2;
        TreeNode* head = new TreeNode(a[m]);
        TreeNode* l = aux(s, m, a);
        TreeNode* r = aux(m + 1, e, a);
        head->left = l;
        head->right = r;
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return aux(0, n, nums);
    }
};