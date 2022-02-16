/*
 * @Author: vihowe
 * @Date: 2022-02-15 09:10:12
 * @LastEditTime: 2022-02-15 16:39:27
 * @FilePath: /leetcode/binaryTree.cc
 */
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Soulution {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    preorder(root, res);
    return res;
  }

  void preorder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }

  void inorder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

  void postorder(TreeNode *root, std::vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }

  // 迭代版遍历
  std::vector<int> preOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *cur = s.top();
      s.pop();
      res.push_back(cur->val);

      if (cur->right) {
        s.push(cur->right);
      }
      if (cur->left) {
        s.push(cur->left);
      }
    }
    return res;
  }

  std::vector<int> inOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<int> res;
    std::stack<TreeNode*> s;
    TreeNode* cur = root;
    while (cur || !s.empty()) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      res.push_back(cur->val);
      cur = cur->right;
    }
  }

  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return {};
    }
    std::vector<std::vector<int>> res;
    std::vector<int> temp;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int qLen = q.size();
      for (int i = 0; i < qLen; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        temp.push_back(cur->val);
        res.push_back(temp);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      temp.clear();
    }
    return res;
  }

  std::vector<int> levelorder(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> res;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();
      res.push_back(cur->val);
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return isMirror(root->left, root->right);
  }
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) {
      return true;
    }
    if (!t1 || !t2) {
      return false;
    }
    return (t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
  }


  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);

  }

  bool hasPathSum2(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    
    std::queue<TreeNode*> nodeQ;
    std::queue<int> valQ;

    nodeQ.push(root);
    valQ.push(root->val);

    while (!nodeQ.empty()) {
      TreeNode *cur = nodeQ.front();
      int temp = valQ.front();
      nodeQ.pop();
      valQ.pop();
      if (!cur->left && !cur->right) {
        if (temp == targetSum) {
          return true;
        }
        continue;
      }
      if (cur->left) {
        nodeQ.push(cur->left);
        valQ.push(temp + cur->left->val);
      }

      if (cur->right) {
        nodeQ.push(cur->right);
        valQ.push(temp + cur->right->val);
      }
    }
    return false;
  }

};