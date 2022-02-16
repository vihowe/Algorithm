#include <iostream>
#include <cstring>

const int MaxLen = 80;
char board[MaxLen][MaxLen];
bool visited[MaxLen][MaxLen];

int w, h, minStep;
// for directions
int to[4][2] = {
  {0,1},{1,0},{0,-1},{-1,0}
};

void DFS(int x1, int y1, int x2, int y2, int step, int f)
{
  if((x1 == x2) && (y1 == y2))
  {
    minStep = step < minStep ? step : minStep;
    return;
  }
  if(step >= minStep)
  {
    return;
  }
  for(int i = 0; i < 4; ++i)
  {
    int x = x1 + to[i][0], y = y1 + to[i][1];
    if((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2) && 
      ((board[y][x] == ' ') && (visited[y][x] == false) || 
        (x == x2 && y == y2 && board[y][x] == 'X')
      )
    )
    {
      visited[y][x] = true;
      if(f != i)
      {
        ++step;
      }
      DFS(x, y, x2, y2, step, i);

      // 回溯
      visited[y][x] = false;
      if(f != i)
      {
        --step;
      }
    }
  }
}

int main()
{
  int board_num = 0;
  while(std::cin >> w >> h)
  {
    if(w == 0 && h == 0)
      break;
    ++board_num;
    std::cout << "Board #" << board_num << ":" << std::endl;
    for(int i = 0; i < MaxLen; ++i)
    {
      board[0][i] = board[i][0] = ' ';
    }

    for(int i = 1; i <= h; ++i)
    {
      getchar();
      for(int j = 1; j <= w; ++j)
      {
        board[i][j] = getchar();
      }
    }

    // 在矩形板最外层加一圈格子
    for(int j = 0; j <= w; ++j)
    {
      board[h+1][j+1] = ' ';
    }
    for(int i = 0; i <= h; ++i)
    {
      board[i+1][w+1] = ' ';
    }
    
    int x1, y1, x2, y2, count = 0;
    while((std::cin >> x1 >> y1 >> x2 >> y2) && x1 > 0)
    {
      ++count;
      minStep = 1 << 30;
      memset(visited, false, sizeof(visited));

      DFS(x1, y1, x2, y2, 0, -1);
      if (minStep < (1<<30))
      {
        std::cout << "Pair " << count << ": " << minStep << " segments." << std::endl;
      }
      else
      {
        std::cout << "Pair " << count << ": impossible." << std::endl;
      }
    }
    std::cout << std::endl;
  }

}



