#include <iostream>
#include <algorithm>

int main()
{
  int N;
  std::cin >> N;

  int data[110];
  int dp[110];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < N; ++i)
  {
    std::cin >> data[i];
  }
  dp[0] = 1;
  
  for(int i = 1; i < N; ++i)
  {
    int temp = 0;
    for(int j = 0; j < i; ++j)
    {
      if(data[i] > data[j])
      {
        temp = dp[j] > temp ? dp[j] : temp;
      }
    }
    dp[i] = temp + 1;
  }
  int ret = 1;
  for(int i = 0; i < N; ++i)
  {
    if (dp[i] > ret)
      ret = dp[i];
  }
  std::cout << ret << std::endl;
  

  return 0;
}