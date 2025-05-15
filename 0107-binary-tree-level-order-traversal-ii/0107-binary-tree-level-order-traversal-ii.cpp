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
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vvi ans;
    if (!root) return ans;
    queue<TreeNode *> q;
    q.push(root);
    vi comp;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto *front = q.front();
        q.pop();
        comp.pb(front->val);
        if (front->left)
          q.push(front->left);
        if (front->right)
          q.push(front->right);
      }
      ans.pb(comp);
      comp.clear();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};