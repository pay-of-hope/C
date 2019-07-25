/**
 * 选择排序：
 * 考虑排序存储在数组A中的n个数：首先找到A中的最小元素并将其与A[1]中的元素进行交换。
 * 接着，找到A中的此最小元素并将其与A[2]中的元素进行交换。
 * 对A中的前n-1个元素按该方式继续。
 * 该算法称为选择算法。
 */
#include<iostream>
#define N 1000005
using namespace std;

typedef struct
{
  int x;
} num;
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

void selectionsort(int n)
{
    int m, i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
      m = i;
      for(j = i + 1; j < n; j++)
      {
        if(arr[m].x > arr[j].x)
        {
          m = j;;
        }
      }
      temp = arr[i].x;
      arr[i].x = arr[m].x;
      arr[m].x = temp;
    }
}

int main()
{
  int i = 0;
  while(cin >> arr[i].x && arr[i].x != 0)
  {
    i++;
  }
  selectionsort(i);
  show(i);
  return 0;
}
