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
    TreeNode* help(vector<int>& nums, int start, int end) {
        if (start == end) return new TreeNode(nums[start]);
        else if (start > end) return NULL;
        int index = (start+end)/2;
        TreeNode* root = new TreeNode(nums[index]);
        root->left = help(nums, start, index - 1);
        root->right = help(nums, index + 1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = help(nums, 0, nums.size()-1);
        return root;
    }
};

// Note: if start==end, then this num has not been added to tree
// else if start > end, then this num has already been added to tree
