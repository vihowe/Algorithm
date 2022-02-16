/*
 * @Author: vihowe
 * @Date: 2022-01-21 11:09:46
 * @LastEditTime: 2022-01-26 17:44:38
 * @FilePath: /leetcode/eggDropping.cc
 */
// 给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

// 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，
// 从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

// 每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。
// 如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

// 请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
// DP方程：f(k,n): k个鸡蛋，n层楼，确定f的次数
// f(1,n) = n: 最坏需要试n次，（f=n）
// f(k,n) = 1 + max(f(k-1, n/2-1), f(k, n-n/2))
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> ret = std::vector<std::vector<int>>(110, std::vector<int>(10010, -1));
  int max(int a, int b) {
    return a > b ? a : b;
  }

  int min(int a, int b) {
    return a < b ? a : b;
  }
  int superEggDrop(int k, int n) {
  
    if (k == 1) {
      return n;
    }
    if (n == 0) {
      return 0;
    }
    if (ret[k][n] != -1) {
      return ret[k][n];
    }

    int res = 1 << 30;
    int low = 1, high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int broken = superEggDrop(k-1, mid - 1);
      int notBroken = superEggDrop(k, n - mid);
      if (broken > notBroken) {
        high = mid - 1;
        res = min(res, broken + 1);
      }
      else {
        low = mid + 1;
        res = min(res, notBroken + 1);
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   res = min(res, 1 + max(superEggDrop(k-1, i - 1), superEggDrop(k, n - i)));
    // }
    ret[k][n] = res;
    return ret[k][n];
  }
};


int main() {
  Solution s;
  std::cout << s.superEggDrop(2, 9) << std::endl;
}