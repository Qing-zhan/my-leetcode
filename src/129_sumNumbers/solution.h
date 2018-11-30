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
    int sumNumbers(TreeNode* root, int prev = 0) {
        if (root == NULL) return 0;
        int temp = root->val + prev * 10;
        if (root->left == NULL && root->right == NULL) return temp;

        int next = 0;
        next += sumNumbers(root->left, temp);
        next += sumNumbers(root->right, temp);
        return next;
    }
};
