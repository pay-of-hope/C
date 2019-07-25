/**
 * 归并排序/分治法排序：
 * 将存储有n个元素的A数组一直平分成2个数组，分别进行排序，一直重复这个操作；
 * 当只有一个元素时，排序的序列就是本身；回到上一级；
 * 合并每一级的两个数组，即可得到排序完成的数组。
 */

#include<iostream>
using namespace std;
#define N 100005

typedef struct
{
  int x;
}num;
num arr[N];

void show(int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    cout << arr[i].x << ' ';
  }
  cout << endl;
}

void merge(int s, int mid, int e)
{
  num Lt[mid - s + 1], Rt[e - mid];
  int i, j, m;
  for(i = s, j = 0; i <= mid; i++)
  {
    Lt[j++].x = arr[i].x;
  }
  Lt[j].x = INT_MAX;
  for(i = mid + 1, j = 0; i <= e; i++)
  {
    Rt[j++].x = arr[i].x;
  }
  Rt[j].x = INT_MAX;
  i = s;
  m = 0;
  j = 0;
  while(i <= e)
  {
    if(Lt[m].x > Rt[j].x)
    {
      arr[i++].x = Rt[j].x;
      j++;
    }
    else{
      arr[i++].x = Lt[m].x;
      m++;
    }
  }
}

void mergesort(int s, int e)
{
  if(e - s > 0)
  {
    int mid = (s + e) >> 1;
    mergesort(s, mid);
    mergesort(mid + 1, e);
    merge(s, mid, e);
  }
  }
int main()
{
  int i = 0;
  while(cin >> arr[i].x && arr[i].x != 0)
  {
    i++;
  }
  mergesort(0, i - 1);
  show(i);
  return 0;
}
