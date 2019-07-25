/**
 * 0-1背包问题
 */

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
  //物品数量，背包容量
  int weight, num;
  cin >> weight >> num;
  //申请重量，价值，F的空间
  int * W, * Val, * F;
  W = new int [num+1];
  Val = new int [num+1];
  F = new int [weight+1];
  int i;
  //初始化F
  for(i = 0; i <= weight; i++)
  {
    *(F+i) = 0;
  }
  //物品重量
  *W = 0;
  *Val = 0;
  for(i = 1; i <= num; i++)
  {
    cin >> *(W+i);
  }
  //物品价值
  for(i = 1; i <= num; i++)
  {
    cin >> *(Val+i);
  }

  for(i = 1; i <= num; i++)
  {
    for(int v = weight; v >= *(W+i); v--)
    {
      F[v] = max(F[v], F[v - *(W+i)] + *(Val+i));
    }
  }
  cout << F[weight] << endl;
  delete []W;
  delete []Val;
  delete []F;
  return 0;
}
