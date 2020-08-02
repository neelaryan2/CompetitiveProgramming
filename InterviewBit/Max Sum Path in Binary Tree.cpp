/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using pii = pair<int, int>;
#define x first
#define y second
const int inf = 1e9;
pii solve(TreeNode* t) {
    if (t == NULL) return {0, 0};
    pii l = solve(t->left), r = solve(t->right);
    l.x = max(0, l.x), r.x = max(0, r.x);
    if (t->left == NULL) l.y = -inf;
    if (t->right == NULL) r.y = -inf;
    pii ret = {max(l.x, r.x) + t->val, max({l.y, r.y, l.x + r.x + t->val})};
    return ret;
}
int Solution::maxPathSum(TreeNode* A) {
    pii p = solve(A);
    return p.y;
}
