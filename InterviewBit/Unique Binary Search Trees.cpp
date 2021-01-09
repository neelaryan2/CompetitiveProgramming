/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> gen(int l, int r) {
    if (l > r) return {NULL};
    if (l == r) return {new TreeNode(l)};
    vector<TreeNode*> ans;
    for (int i = l; i <= r; i++) {
        auto vl = gen(l, i - 1), vr = gen(i + 1, r);
        for (auto lef : vl) {
            for (auto righ : vr) {
                TreeNode* head = new TreeNode(i);
                head->left = lef, head->right = righ;
                ans.push_back(head);
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    return gen(1, A);
}
