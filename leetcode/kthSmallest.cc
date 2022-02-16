/*
 * @Author: vihowe
 * @Date: 2022-02-15 08:38:39
 * @LastEditTime: 2022-02-15 08:54:24
 * @FilePath: /leetcode/kthSmallest.cc
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int getNum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return getNum(root->left) + getNum(root->right) + 1;
  }
  int kthSmallest(TreeNode* root, int k) {
    int n = getNum(root->left);
    if (n == k - 1) {
      return root->val;
    }
    else if (n > k - 1) {
      return kthSmallest(root->left, k);
    }
    else {
      return kthSmallest(root->right, k - n - 1);
    }
  }
};