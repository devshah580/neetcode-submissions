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

        vector<vector<int>> result;
        std::queue<TreeNode*> to_check;
        to_check.push(root);
        while(!to_check.empty()) {
            int currSize = to_check.size();
            vector<int> currVec;
            for(int i = 0; i < currSize; i++) {
                TreeNode* currNode = to_check.front();
                to_check.pop();
                currVec.push_back(currNode->val);
                if(currNode->left != nullptr) {
                    to_check.push(currNode->left);
                }
                if(currNode->right != nullptr) {
                    to_check.push(currNode->right);
                }
            }
            result.push_back(currVec);
        }
        return result;
    }
};
