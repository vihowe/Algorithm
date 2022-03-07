/*
 * @Author: vihowe
 * @Date: 2022-03-07 19:37:07
 * @LastEditTime: 2022-03-07 19:41:48
 * @FilePath: /Algorithm/leetcode/tree.cc
 */
#include <vector>

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {

public:
  TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root || root == p || root == q)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
      return root;
    return left ? left : right;
  }
};