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
    int inorder(TreeNode* root, int k, int& count) {
        if(root == nullptr) {
            return 0;
        }
        int left = inorder(root->left, k, count);
        if(count >= k) {
            return left;
        }

        count++;
        if(k == count) {
            return root->val;
        }

        return inorder(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, k, count);
    }
};
