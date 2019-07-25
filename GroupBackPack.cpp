#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void input(vector<vector<int>>&, int, int); //输入
int main()
{
  int K; // 物品组数
  cout << "请输入物品组数:" << endl;
  cin >> K;
  vector<vector<int>> cap(K);
  vector<vector<int>> value(K);
  for(int i = 0; i < K; i++)
  {
    int k;
    cout << "请输入第" << i+1 << "组物品数量:" << endl;
    cin >> k;
    cout << "请输入第" << i+1 << "组物品容量数组:" << endl;
    input(cap, i, k);
    cout << "请输入第" << i+1 << "组物品价值数组:" << endl;
    input(value, i, k);
  }
  int capacity;
  cout << "请输入背包容量:" << endl;
  cin >> capacity;
  vector<int> dp(capacity+1, 0);
  for(int i = 0; i < K; i++)
  {
    for(int j = capacity; j >= cap[i][0]; j--)
    {
      for(int k = 0; k < cap[i].size(); k++)
      {
        dp[j] = max(dp[j], dp[j - cap[i][k]] + value[i][k]);
      }
    }
  }
  cout << dp[capacity] << endl;
  return 0;
}

void input(vector<vector<int>>& arr, int i, int k)
{
  for(int j = 0; j < k; j++)
  {
    int num;
    cin >> num;
    arr[i].push_back(num);
  }
}
