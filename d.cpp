#include<iostream>
#include<vector>

using namespace std;
int max(int a, int b)
{
  if(a>b)return a;
  else return b;
}

int get_m(int ds[101][101], int n)
{
  int m = ds[n][1];
  for(int i = 2; i <= n;i++)
  {
    m = max(m,ds[n][i]);
  }
  return m;
}
int main()
{
  int C, i = 0;
  cin >> C;
  while(i++<C)
  {
  int n;
  cin >> n;
  int a,sum=0;
  int dp[101][101]={0};
  int i;
  for(i = 1; i <= n; i++)
  {
    for(int j = 1; j<=i;j++)
    {
      cin >> a;
      if(j==1&&j==i)
      {
        dp[i][j]=dp[i-1][j]+a;
      }
      else
      {
        dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a;
      }
    }

  }
  cout << get_m(dp, n) <<endl;
}


  return 0;
}
