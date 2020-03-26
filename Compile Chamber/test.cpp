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
	using vii = vector<vector<int>>;
	vii pathSumAux(TreeNode* root, int sum) {
		vii ans;
		if (root == nullptr) return ans;
		if (root->left == nullptr && root->right == nullptr) {
			if (sum != root->val) return ans;
			ans.push_back(vector<int>(1, sum));
			return ans;
		}
		if (root->left == nullptr) {
			ans = pathSumAux(root->right, sum - root->val);
			for (auto& v : ans) v.push_back(root->val);
			return ans;
		}
		if (root->right == nullptr) {
			ans = pathSumAux(root->left, sum - root->val);
			for (auto& v : ans) v.push_back(root->val);
			return ans;
		}
		vii ans1 = pathSumAux(root->left, sum - root->val);
		vii ans2 = pathSumAux(root->right, sum - root->val);
		for (auto& v : ans1) {
			v.push_back(root->val);
			ans.push_back(v);
		}
		for (auto& v : ans2) {
			v.push_back(root->val);
			ans.push_back(v);
		}
		return ans;
	}
	vii pathSum(TreeNode* root, int sum) {
		vii ans = pathSumAux(root, sum);
		for (auto& v : ans)
			reverse(v.begin(), v.end());
		return ans;
	}
};