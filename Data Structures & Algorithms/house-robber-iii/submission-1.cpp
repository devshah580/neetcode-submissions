/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        if(dp.count(root)) {
            return dp[root];
        }

        int result = root->val;
        if(root->left != nullptr) {
            result += rob(root->left->left);
            result += rob(root->left->right);
        }

        if(root->right != nullptr) {
            result += rob(root->right->left);
            result += rob(root->right->right);
        }
        result = max(result, rob(root->left) + rob(root->right));
        dp[root] = result;
        return result;
    }
};