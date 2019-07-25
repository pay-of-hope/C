#include<iostream>
using namespace std;

int main()
{
  int n;
  while(cin >> n && n != 0)
  {
  int i = 1;
  int num[60] = {0};
  while(i <= n)
  {
    if(i<=3)
    {
      num[i] = num[i-1] + 1;
    }
    else
    {
      num[i] = num[i-1]+num[i-3];
    }
    i++;
  }
  cout << num[n] << endl;
}
  return 0;
}
