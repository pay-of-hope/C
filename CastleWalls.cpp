#include<iostream>
using namespace std;

void castlewalls(int *a, int lt, int rt)
{
  if(rt > lt)
  {
    int mid = (lt + rt) >> 1;
    castlewalls(a, lt, mid);
    castlewalls(a, mid+1, rt);
    int L[mid-lt+1], R[rt-mid], i, j;
    for(i = 0, j = lt; i <= mid-lt; i++)
    {
      L[i] = a[j++];
    }
    for(i = 0, j = mid+1; i <= rt-mid-1; i++)
    {
      R[i] = a[j];
    }
    int m;
    for(i = 0, j = 0, m = lt; m <= rt; m++)
    {
      if(i > mid-lt)
      {
        a[m] = R[j++];
      }
      else if(j > rt-mid-1)
      {
        a[m] = L[i++];
      }
      else if(R[i] < L[j])
      {
        for(int k = i; k <= mid-lt; k++)
        {
          cout << "(" << L[k] << "," << R[j] << ")" << endl;
        }
        a[m] = R[j++];
      }
      else
      {
        a[m] = L[i++];
      }
    }
  }
}
int main()
{
  const int N = 100;
  int a[N], i = 0;
  while(cin >> a[i] && a[i] != 0)
  {
    i++;
  }
  castlewalls(a, 0, i-1);
  return 0;
}
