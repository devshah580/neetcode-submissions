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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        std::queue<TreeNode*> to_check;
        int prevCount = 1;
        to_check.push(root);
        vector<int> result;
        while(!to_check.empty()) {
            int count = 0;
            while(prevCount > 0) {
                prevCount--;
                TreeNode* curr = to_check.front();
                to_check.pop();
                if(curr->left != nullptr) {
                    to_check.push(curr->left);
                    count++;
                }
                if(curr->right != nullptr) {
                    to_check.push(curr->right);
                    count++;
                }
                if(prevCount == 0) {
                    result.push_back(curr->val);
                }
            }
            prevCount = count; 
        }
        return result;
    }
};
