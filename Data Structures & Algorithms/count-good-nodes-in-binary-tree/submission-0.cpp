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
    void dfs(TreeNode* root, stack<int>& max, int& result) {
        if(root == nullptr) {
            return;
        }
        if(max.size() == 0 || root->val >= max.top()) {
            max.push(root->val);
            result++;
        }
        dfs(root->left, max, result);
        dfs(root->right, max, result);

        if(root->val == max.top()) {
            max.pop();
        }
    }
    int goodNodes(TreeNode* root) {
        stack<int> max;
        int result = 0;
        dfs(root, max, result);
        return result;
    }
};
