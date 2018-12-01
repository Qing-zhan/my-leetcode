/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            //result.push_back(temp);
            result.insert(result.begin(), temp);
        }
        return result;
    }
};

// To reverse a vector, one can also use std::reverse
// e.g. std::reverse(result.begin(), result.end());
