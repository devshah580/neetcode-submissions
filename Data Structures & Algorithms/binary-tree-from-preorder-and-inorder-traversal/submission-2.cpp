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
    TreeNode* constructSubTree(int left, int right, vector<int>& preorder, unordered_map<int, int>& indexes, int& preIndex) {
        if(right < left) {
            return nullptr;
        }

        int currIndex = indexes[preorder[preIndex]];

        TreeNode* newNode = new TreeNode(preorder[preIndex]);
        preIndex++;
        newNode->left = constructSubTree(left, currIndex - 1, preorder, indexes, preIndex);
        newNode->right = constructSubTree(currIndex + 1, right, preorder, indexes, preIndex);
        return newNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexes;
        for(int i = 0; i < preorder.size(); i++) {
            indexes[inorder[i]] = i;
        }

        int preIndex = 0;

        return constructSubTree(0, inorder.size() - 1, preorder, indexes, preIndex);
    }
};
