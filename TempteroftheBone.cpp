#include<iostream>
using namespace std;

bool find(char b[7][7], int i, int j, int M, int N, int T, int t, int d)
{
  if(i >= 0 && j >= 0 && (b[i][j] == '.' || b[i][j] == 'S') && t < T & i < M && j < N)
  {
    bool d_d = false, d_u = false, d_r = false, d_l = false;
    if(d != 1 && i > 0 && b[i - 1][j] != 'X')
    {
      d_l = find(b, i - 1, j, M, N, T, t + 1, 2);
    }
    if(d != 2 && i < M - 1 && b[i + 1][j] != 'X')
    {
      d_r = find(b, i + 1, j, M, N, T, t + 1, 1);
    }
    if(d != 3 && j > 0 && b[i][j - 1] != 'X')
    {
      d_u = find(b, i, j - 1, M, N, T, t + 1, 4);
    }
    if(d != 4 && j < N - 1 && b[i ][j + 1] != 'X')
    {
      d_d = find(b, i, j + 1, M, N, T, t + 1, 3);
    }
    return d_l || d_d || d_r || d_u;
  }
  else if(t == T && b[i][j] == 'D')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  char b[7][7];
  int M, N, T;
  int m, n;
  while(cin >> M >> N >> T && M != 0 && N != 0 && T != 0)
  {
    int i, j;
    for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
      {
        cin >> b[i][j];
        if(b[i][j] == 'S')
        {
          m = i;
          n = j;
        }
      }
    }
    int t = 0;
    int d = 0;
    if(find(b, m, n, M, N, T, t, d) == true)
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}
