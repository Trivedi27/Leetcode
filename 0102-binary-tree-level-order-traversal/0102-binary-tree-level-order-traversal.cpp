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
    void get_lot(TreeNode* node, vector<vector<int>>& lot, int depth)
    {
        if (node == nullptr)
        {
            return;
        }

        depth++;

        if (size(lot) < depth)
        {
            vector<int> temp;
            temp.emplace_back(node->val);
            lot.emplace_back(temp);
        }
        else
        {
            lot[depth - 1].emplace_back(node->val);
        }

        get_lot(node->left, lot, depth);
        get_lot(node->right, lot, depth);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lot;
        int depth = 0;
        get_lot(root, lot, 0);
        return lot;
    }
};