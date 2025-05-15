
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        // create a map to store values with their index in inorder array
        unordered_map<int, int> indexes;
        for (int i = 0; i < n; ++i)
            indexes[inorder[i]] = i;
        // call the helper function
        return build(inorder, 0, n - 1, postorder, 0, n - 1, indexes);
    }
    TreeNode* build(vector<int>& inorder, int left_in, int right_in,
                    vector<int>& postorder, int left_post, int right_post,
                    unordered_map<int, int>& indexes) {
        // base case is when either of those pointers cross each other as it
        // means iteration is done
        if (left_in > right_in || left_post > right_post)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[right_post]);
        //this is where the map comes in,for the root value in post order we get the index in inorder for easy k
        int inorder_index = indexes[postorder[right_post]];
        //now this is the index where the array gets divided into two parts so we will get the middle index
        int cuthere = inorder_index - left_in;
        //adjust the pointers as required for each recursion
        root->left = build(inorder, left_in, inorder_index - 1, postorder,
                           left_post, left_post + cuthere - 1, indexes);
        root->right = build(inorder, inorder_index + 1, right_in, postorder,
                            left_post + cuthere, right_post - 1, indexes);
        return root;
    }
};
