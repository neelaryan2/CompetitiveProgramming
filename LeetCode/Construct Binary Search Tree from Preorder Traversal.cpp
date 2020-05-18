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
    int pos = 0;

   public:
    TreeNode* buildBinary(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        TreeNode* root = NULL;
        if (start <= end) {
            int i;
            for (i = start; i <= end; i++) {
                if (inorder[i] == preorder[pos])
                    break;
            }
            root = new TreeNode(inorder[i]);
            pos++;
            root->left = buildBinary(preorder, inorder, start, i - 1);
            root->right = buildBinary(preorder, inorder, i + 1, end);
        }
        return (root);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return buildBinary(preorder, inorder, 0, n - 1);
    }
};