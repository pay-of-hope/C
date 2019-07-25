#include<iostream>
using namespace std;

int main()
{
  int n,i=1;
  cin >> n;
  while(i++<=n)
  {
    int a, b,i,j;
    long long bee[51]={0};
    cin >> a >> b;
    bee[a] = 1;
    for(i=a+1;i<=b;i++)
    {
      bee[i]=bee[i-1]+bee[i-2];
    }
    cout << bee[b] << endl;
  }
  return 0;

}
