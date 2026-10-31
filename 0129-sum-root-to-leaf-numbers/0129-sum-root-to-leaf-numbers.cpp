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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int totalSum = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        while (!st.empty()) {
            auto [node, currentNum] = st.top();
            st.pop();
            if (!node->left && !node->right) {
                totalSum += currentNum;
                continue;
            }
            if (node->right) {
                st.push({node->right, currentNum * 10 + node->right->val});
            }
            if (node->left) {
                st.push({node->left, currentNum * 10 + node->left->val});
            }
        }
        return totalSum;
    }
};