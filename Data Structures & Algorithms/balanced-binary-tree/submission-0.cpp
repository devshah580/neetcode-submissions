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
    int dfs(TreeNode* root, bool& inBalanced) {
        if(root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, inBalanced);
        int right = dfs(root->right, inBalanced);
        if(inBalanced == false) {
            inBalanced = abs(left - right) >= 2;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool inBalanced = false;
        dfs(root, inBalanced);
        return !inBalanced;
    }
};
