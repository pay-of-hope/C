/**
 * 插入排序：
 * 对存储由n个元素的数组A进行排序；从第二个元素楷书，到第n个元素结束，
 * 将他们依次插入到前面已排好的序列中的正确位置；
 */
#include<iostream>
#define N 100005
using namespace std;

typedef struct
{
  int x;
} num;
num arr[N];

int show(int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    cout << arr[i].x << ' ';
  }
  cout << endl;
  return 0;
}

int insertsort(int n)
{
  int key;
  for(int i = 1; i < n; i++)
  {
    key = arr[i].x;
    int j = i - 1;
    while(j >= 0 && arr[j].x > key)
    {
      arr[j+1].x = arr[j].x;
      j--;
    }
    arr[j+1].x = key;
  }
  return 0;
}

int main()
{
  int i = 0;
  while(cin >> arr[i].x && arr[i].x != 0)
  {
    i++;
  }
  insertsort(i);
  show(i);
  return 0;
}
