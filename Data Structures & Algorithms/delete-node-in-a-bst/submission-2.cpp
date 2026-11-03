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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while(curr != nullptr) {
            if(curr->val == key) {
                break;
            } else if(curr->val < key) {
                parent = curr;
                curr = curr->right;
            } else {
                parent = curr;
                curr = curr->left;
            }
        }

        if(curr == nullptr) {
            return root;
        }

        TreeNode* nextCurr = curr->left;
        TreeNode* nextParent = curr;
        while(nextCurr != nullptr && nextCurr->right != nullptr) {
            nextParent = nextCurr;
            nextCurr = nextCurr->right;
        }

        if(nextCurr != nullptr) {
            if(nextParent->left == nextCurr) {
                nextParent->left = nullptr;
            } else {
                nextParent->right = nullptr;
            }

            if(parent != nullptr && parent->left == curr) {
                parent->left = nextCurr;
            } else if(parent != nullptr) {
                parent->right = nextCurr;
            } else {
                root = nextCurr;
            }
            nextCurr->left = curr->left;
            nextCurr->right = curr->right;
        } else {
            if(parent != nullptr && parent->left == curr) {
                parent->left = curr->right;
            } else if(parent != nullptr) {
                parent->right = curr->right;
            } else {
                root = curr->right;
            }
        }
        return root;

    }
};