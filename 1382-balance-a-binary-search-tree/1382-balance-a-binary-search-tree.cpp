/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        return build(values, 0, values.size() - 1);
    }
    void inorder(TreeNode* node, vector<int>& values) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
    TreeNode* build(vector<int>& values, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(values[mid]);
        node->left = build(values, left, mid - 1);
        node->right = build(values, mid + 1, right);
        return node;
    }
};