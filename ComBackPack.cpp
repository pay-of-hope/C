/**
 * 完全背包问题
 */

#include<iostream>
#include<array>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
  array<int, 5> weight {5, 4, 7, 2, 6};
  array<int, 5> value {12, 3, 10, 3, 6};
  int capacity, sum;
  cout << "请输入背包容量大小：";
  cin >> capacity;
  //获取处理后的价值以及重量数组，转换为0-1背包问题
  for(auto i : weight)
  {
    if(i <= capacity)
      sum = sum + 1 + log(capacity/i)/log(2);
  }
  array<int, 12> new_weight;
  array<int, 12> new_value;
  int k = 0;
  for(int i = 0; i< 5; i++)
  {
    int j = 0;
    int num = log(capacity/weight[i])/log(2);
    while(j++ <= num)
    {
      new_weight[k] = weight[i]*pow(2,j-1);
      new_value[k] = value[i]*pow(2,j-1);
      k++;
    }
  }
  //0-1背包问题处理
  vector<int> dp(capacity+1, 0);
  vector<int>::iterator d;
  d = dp.begin();
  for(int i = 0; i < sum; i++)
  {
    for(k = new_weight[i]; k <= capacity; k++)
    {
      *(d+k) = max(*(d+k), *(d+k-new_weight[i]) + new_value[i]);
    }
  }
  cout << *(d+capacity) << endl;
  return 0;
}
