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

    int numGoodNodes(TreeNode* node, int maxi) {
        if (!node) {
            return 0;
        }

        int maxSoFar = max(maxi, node->val);
        int countLeft = numGoodNodes(node->left, maxSoFar);
        int countRight = numGoodNodes(node->right, maxSoFar);

        return (maxi <= node->val ? 1 : 0) + countLeft + countRight;
    }

    int goodNodes(TreeNode* root) {
        return numGoodNodes(root, INT_MIN);
    }
};
