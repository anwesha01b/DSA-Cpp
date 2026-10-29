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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
    void dfs(TreeNode* node, int remaining, vector<int>& path,
             vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }
        path.push_back(node->val);
        if (!node->left && !node->right && remaining == node->val) {
            result.push_back(path);
        } else {
            dfs(node->left, remaining - node->val, path, result);
            dfs(node->right, remaining - node->val, path, result);
        }
        path.pop_back();
    }
};