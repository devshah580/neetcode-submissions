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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::queue<TreeNode*> to_check;
        int prevCount = 1;
        to_check.push(root);
        vector<vector<int>> result;
        while(!to_check.empty()) {
            int count = 0;
            vector<int> level;
            while(prevCount > 0) {
                prevCount--;
                TreeNode* curr = to_check.front();
                level.push_back(curr->val);
                to_check.pop();
                if(curr->left != nullptr) {
                    to_check.push(curr->left);
                    count++;
                }
                if(curr->right != nullptr) {
                    to_check.push(curr->right);
                    count++;
                }
            }
            result.push_back(level);
            prevCount = count; 
        }
        return result;
    }
};
