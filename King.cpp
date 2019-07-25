#include<iostream>
using namespace std;

long long C(int m, int n)
{
  long long s = 1;
  for(int i = n + 1; i <= m; i++)
  {
    s *= i;
  }
  for(int i = 2; i <= m-n; i++)
  {
    s = s/i;
  }
  return s;
}

int main()
{
  int test_num, i = 0;
  cin >> test_num;
  while(i++ < test_num)
  {
  long long dp[2][21] = {0};
  dp[0][1] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;
  dp[0][2] = 1;
  int num, n;
  cin >> num >> n;
  for(int i = 3;i <= n; i++)
  {
    long long sum = dp[0][i-1]+dp[1][i-1];
    for(int j = 1; j <= i-2; j++)
    {
      sum += C(i-1,j)*dp[1][j]*dp[0][i-1-j];
    }
    dp[0][i] = sum / 2;
    dp[1][i] = sum / 2;
  }
  cout << num << ' ';
  if(n != 1)
    cout << dp[0][n]+dp[1][n] << endl;
  else
    cout << 1 << endl;
}
  return 0;
}
