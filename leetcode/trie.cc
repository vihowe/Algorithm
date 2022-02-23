/*
 * @Author: vihowe
 * @Date: 2022-02-23 14:48:54
 * @LastEditTime: 2022-02-23 15:47:06
 * @FilePath: /Algorithm/leetcode/trie.cc
 */
#include <string>
#include <vector>

class Trie {
private:
  std::vector<Trie*> children;
  bool isEnd;

public:
  Trie() : children(26), isEnd(false) {};

  void insert(std::string str)
  {
    Trie *node = this;
    for (auto ch : str)
    {
      if (!node->children[ch - 'a'])
      {
        node->children[ch - 'a'] = new Trie();
      }
      node = node->children[ch - 'a'];
    }
    node->isEnd = true;
  }
  
  bool search(std::string str)
  {
    Trie *node = this;
    for (auto ch : str)
    {
      if (node->children[ch - 'a'])
      {
        node = node->children[ch - 'a'];
      }
      else
        return false;
    }
    return node->isEnd;
  }

  bool startsWith(std::string str)
  {
    Trie *node = this;
    for (auto ch : str)
    {
      if (node->children[ch - 'a'])
      {
        node = node->children[ch - 'a'];
      }
      else
      {
        return false;
      }
    }
    return true;
  }

  std::vector<std::string> findWords(std::vector<std::vector<char>> &board, 
                                     std::vector<std::string> words)
  {
    int m = board.size(), n = board[0].size();
    
  }

};
