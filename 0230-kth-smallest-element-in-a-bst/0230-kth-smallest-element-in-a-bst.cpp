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

int rec(TreeNode *root, int *k) {
    if (k == 0) return root->val;
    if (!root) return 0;
    int left = rec(root->left, k);
    if (left) return left;
    if (!(--*k)) return root->val;
    return rec(root->right, k);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return rec(root, &k);
    }
};