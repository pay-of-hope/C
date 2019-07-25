#include<iostream>
using namespace std;
int max(int a, int b)
{
  if(a>b)return a;
  else return b;
}

int get_m(int ds[6][6])
{
  int m = ds[5][1];
  for(int i = 2; i< 5;i++)
  {
    m = max(m,ds[5][i]);
  }
  return m;
}
int main()
{

  int a,sum=0;
  int dp[6][6]={0};
  int i;
  for(i = 1; i <= 5; i++)
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
  cout << get_m(dp) <<endl;



  return 0;
}
