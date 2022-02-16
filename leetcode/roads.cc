#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int K, N, R;

struct road
{
  int s;
  int e;
  int L;
  int T;
  road(int ss, int ee, int ll, int tt) : s(ss), e(ee), L(ll), T(tt) {}
};

std::vector<road> roads;
std::unordered_set<int> visited;

int minLen = 1 << 30;
int curLen = 0;

void DFS(int s)
{
  if(s == N)
  {
    minLen = std::min(curLen, minLen);
    return;
  }
  visited.insert(s);

  for(int i = 0; i < roads.size(); ++i)
  {
    road r = roads[i];
    if(r.s == s && (visited.find(r.e) == visited.end()) && K >= r.T)
    {
      curLen += r.L;
      K -= r.T;
      DFS(r.e);
      K += r.T;
      curLen -= r.L;
      visited.erase(s);
    }
  }
}


int main()
{
  std::cin >> K >> N >> R;
  for(int i = 0; i < R; ++i)
  {
    int s, e, L, T;
    std::cin >> s >> e >> L >> T;
    
    roads.push_back(road(s, e, L, T));
  }
  DFS(1);
  minLen = (minLen < (1 << 30) ? minLen : -1);
  std::cout << minLen << std::endl;

  return 0;

}