#include<iostream>
using namespace std;

int main()
{
  int n, i = 0;
  cin >> n;
  while(i++ < n)
  {
    long long  s[42] = {0};
    int f, j = 2;
    cin >> f;
    s[0] = 0;
    s[1] = 1;
    while(j <= f)
    {
      s[j] = s[j-1] + s[j-2];
      j++;
    }
    cout << s[f] << endl;
  }
  return 0;
}
