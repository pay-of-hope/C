#include<iostream>
using namespace std;

int get_len(int n)
{
  int max = 0;
  while(true)
  {
    max++;
    if(n==1) break;
    else if(n & 1)
    {
      n = 3*n + 1;
    }
    else
    {
      n = n/2;
    }
  }
  return max;
}

int main()
{
  int a, b;
  while(cin >> a >> b)
  {
    int i, max = 1;
    cout << a << ' ' << b << ' ';
    if(a>b)
    {
      i = a;
      a = b;
      b = i;
    }
    for(i = a; i <= b; i++)
    {
      int m = get_len(i);
      if(max < m)
      {
        max = m;
      }
    }
     cout << max << endl;
  }
  return 0;
}
