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
    bool subtreeMatch(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr && root == nullptr) {
            return true;
        } else if(root == nullptr || subRoot == nullptr) {
            return false;
        } else if(root->val != subRoot->val) {
            return false;
        } else {
            return subtreeMatch(root->left, subRoot->left) && subtreeMatch(root->right, subRoot->right);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) {
            return false;
        }

        if(root->val == subRoot->val) {
            if(subtreeMatch(root, subRoot)) {
                return true;
            }
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};
