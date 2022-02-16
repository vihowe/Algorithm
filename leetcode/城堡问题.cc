#include <iostream>

const int MAXN = 60;
int room[MAXN][MAXN];
int color[MAXN][MAXN];
int max_area = 0;
int cur_area = 0;
int room_num = 0;


void DFS(int i, int j)
{
  if(color[i][j])
    return;
  
  color[i][j] = room_num;
  ++cur_area;

  if((room[i][j] & 1) == 0)
    DFS(i, j-1);
  if((room[i][j] & 2) == 0)
    DFS(i-1, j);
  if((room[i][j] & 4) == 0)
    DFS(i, j+1);
  if((room[i][j] & 8) == 0)
    DFS(i+1, j);
}


int main()
{
  int r, c;
  std::cin >> r >> c;
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      std::cin >> room[i][j];
    }
  }
  memset(color, 0, sizeof(color));
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      if(!color[i][j])
      {
        cur_area = 0;
        room_num++;
        DFS(i, j);
      }
      max_area = max_area > cur_area ? max_area : cur_area;
    }
  }
  std::cout << room_num << std::endl;
  std::cout << max_area << std::endl;
  return 0;
}