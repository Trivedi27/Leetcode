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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};

        stack<TreeNode*> s1; // Right to left
        stack<TreeNode*> s2; // Left to right

        s2.push(root);
        vector<vector<int>> answer;
        while (!s1.empty() || !s2.empty()) {
            vector<int> ans;
            // left to right
            if (!s2.empty()) {
                while (!s2.empty()) {
                    TreeNode* temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->val);
                    if (temp->left)
                        s1.push(temp->left);
                    if (temp->right)
                        s1.push(temp->right);
                }
            } else {
                while (!s1.empty()) {
                    TreeNode* temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->val);
                    if (temp->right)
                        s2.push(temp->right);
                    if (temp->left)
                        s2.push(temp->left);
                }
            }
            answer.push_back(ans);
        }
        return answer;
    }
};