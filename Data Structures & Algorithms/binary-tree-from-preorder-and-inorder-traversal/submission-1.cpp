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
    TreeNode* constructSubTree(int left, int right, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& indexes) {
        if(right < left) {
            return nullptr;
        }

        if(left == right) {
            TreeNode* newNode = new TreeNode(inorder[left]);
            return newNode;
        }

        int minIndex = INT_MAX;
        for(int i = left; i <= right; i++) {
            minIndex = min(minIndex, indexes[inorder[i]]);
        }

        int temp = left;
        while(inorder[temp] != preorder[minIndex]) {
            temp++;
        }

        TreeNode* newNode = new TreeNode(preorder[minIndex]);
        newNode->left = constructSubTree(left, temp - 1, preorder, inorder, indexes);
        newNode->right = constructSubTree(temp + 1, right, preorder, inorder, indexes);
        return newNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        unordered_map<int, int> indexes;
        for(int i = 0; i < preorder.size(); i++) {
            indexes[preorder[i]] = i;
        }

        int right = 0;
        while(inorder[right] != preorder[0]) {
            right++;
        }

        root->left = constructSubTree(0, right - 1, preorder, inorder, indexes);
        root->right = constructSubTree(right + 1, preorder.size() - 1, preorder, inorder, indexes);

        return root;
    }
};
