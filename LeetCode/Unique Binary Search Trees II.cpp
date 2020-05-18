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
    vector<TreeNode*> aux(int s, int e) {
        vector<TreeNode*> ans;
        if (s > e) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> l = aux(s, i - 1);
            vector<TreeNode*> r = aux(i + 1, e);
            for (auto a : l)
                for (auto b : r) {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = a;
                    tmp->right = b;
                    ans.push_back(tmp);
                }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return aux(1, n);
    }
};