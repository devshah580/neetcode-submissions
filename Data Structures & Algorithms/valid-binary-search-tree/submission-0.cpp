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
    bool preOrder(TreeNode* root, vector<int>& traversal) {
        if(root == nullptr) {
            return true;
        }

        bool left = preOrder(root->left,traversal);
        bool curr = traversal.size() > 0 ? root->val > traversal[traversal.size() - 1] : true;
        traversal.push_back(root->val);
        bool right = preOrder(root->right, traversal);
        return left && right && curr;

    }
    bool isValidBST(TreeNode* root) {
        vector<int> traversal;
        return preOrder(root, traversal);
    }
};
