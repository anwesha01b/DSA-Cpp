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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        int position=0;
        while(!q.empty()){
            auto[node,index]=q.front();
            q.pop();
            position++;
            if(index!=position) return false;
            if(node->left){
                q.push({node->left,2*index});
            }
            if(node->right){
                q.push({node->right, 2*index+1});
            }
        }
        return true;
    }
};