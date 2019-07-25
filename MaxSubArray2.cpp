#include<iostream>
#include<ctime>
using namespace std;

int main()
{
  long long t_1 = clock();
  int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,13,-5,-22,15,-4,7};
  int dp[16]={0};
  int e;
  for(int i = 0; i <= 15; i++)
  {
    if(i==0)
    {
      dp[i] = arr[i];
      e = i;
    }
    else
    {
      if(arr[i] < 0)
      {
        dp[i] = dp[i-1];
      }
      else
      {
        int sum = 0, max = INT_MIN;
        for(int j = i; j > e; j--)
        {
          sum += arr[j];
          if(sum >= max)
          {
            max = sum;
          }
        }
        if(sum > 0 && sum + dp[i-1] > max)
        {
          dp[i] = sum + dp[i-1];
          dp[i] = dp[i] > max?dp[i]:max;
          e = i;
        }
        else
        {
          if(max > dp[i-1])
          {
            dp[i] = max;
            e = i;
          }
          else
          {
            dp[i] = dp[i-1];
          }
        }
      }
    }
  }
  long long t_2 = clock();
  cout << dp[15] << endl;
  return 0;
}
