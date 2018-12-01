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
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        int dep = 0;
        dep = max(depth(root->left), dep);
        dep = max(depth(root->right), dep);
        return dep+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int ldep = depth(root->left);
        int rdep = depth(root->right);
        if (abs(ldep-rdep) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
    
};

// In the solution above, depth of a node is calculated multiple times

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
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int ldep = height(root->left);
        int rdep = height(root->right);
        if (ldep == -1 || rdep == -1 || abs(ldep-rdep) > 1) return -1;
        return max(ldep, rdep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

};

// Use -1 as height when this subtree is unbalanced
