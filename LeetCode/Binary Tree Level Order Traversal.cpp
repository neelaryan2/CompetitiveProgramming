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
    void dfs(TreeNode* v, int h, vector<vector<int>>& ans) {
        if (v == NULL) return;
        if (h == ans.size()) ans.emplace_back();
        ans[h].emplace_back(v->val);
        dfs(v->left, h + 1, ans);
        dfs(v->right, h + 1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};