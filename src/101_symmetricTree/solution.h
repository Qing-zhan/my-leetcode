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
    bool isSame(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        else if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        else return isSame(root->left, root->right);
    }
};


// 稍微更改代码，可以解决诸如左右树是否相同，左右树的结构是否相同；
