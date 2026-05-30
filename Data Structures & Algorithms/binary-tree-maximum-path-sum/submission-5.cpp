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


    pair<int, int> solveAgain(TreeNode* node) {
        if (!node) {
            return {INT_MIN, 0};
        }

        pair<int, int> leftAns = solveAgain(node->left);
        pair<int, int> rightAns = solveAgain(node->right);

        int leftRightSum = max(0, leftAns.second) + max(0, rightAns.second) + node->val;
        int maxLeftRightSum = max(max(leftAns.second, rightAns.second) + node->val, node->val);

        return {max(leftAns.first, max(rightAns.first, leftRightSum)), maxLeftRightSum};
    }

    int maxPathSum(TreeNode* root) {
        return solveAgain(root).first;
    }







};
