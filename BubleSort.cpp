/**
 * 冒泡排序：
 * 反复交换相邻的未按次序排列的元素。
 */

#include<iostream>
using namespace std;

void show(int *a, int i)
{
  for(int j = 0; j <= i; j++)
  {
    cout << a[j] << ' ';
  }
  cout << endl;
}

void bublesort(int *a, int i)
{
  int temp;
  for(int m = 0; m < i; m++)
  {
    for(int n = i; n >= m + 1; n--)
    {
      if(a[n] < a[n-1])
      {
        temp = a[n];
        a[n] = a[n -1];
        a[n - 1] = temp;
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
  bublesort(a, i - 1);
  show(a, i - 1);
  return 0;
}
