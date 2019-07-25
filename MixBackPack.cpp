#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void input(vector<int>&, int); // 输入数据
void MultiBackPack(vector<int>& dp, int capacity, int value, int cap, int w); // 0-1、多重背包问题求解
void ComBackPack(vector<int>& dp, int capacity, int value, int cap); // 完全背包问题求解

int main()
{
  int item_number; // 物品数量
  cout << "请输入物品数量:" << endl;;
  cin >> item_number;
  vector<int> cap; //容量数组
  vector<int> value; //价值数组
  vector<int> section; // 选择数组
  cout << "请输入物品容量:" << endl;;
  input(cap, item_number);
  cout << "请输入物品价值:" << endl;
  input(value, item_number);
  cout << "请输入每项物品可选择的数量:" << endl;
  input(section, item_number);
  int capacity; // 背包容量
  cout << "请输入背包容量:" << endl;
  cin >> capacity;
  vector<int> dp(capacity+1, 0); //背包状态
  vector<int>::iterator cap_iter, value_iter, section_iter, dp_iter;
  cap_iter = cap.begin();
  value_iter = value.begin();
  section_iter = section.begin();
  dp_iter = dp.begin();
  for(int i = 0; i < item_number; i++)
  {
    if(*(section_iter+i) != -1)
    {
      MultiBackPack(dp, capacity, *(value_iter+i), *(cap_iter+i), *(section_iter+i));
    }
    else
    {
      ComBackPack(dp, capacity, *(value_iter+i), *(cap_iter+i));
    }
  }
  cout << *(dp_iter+capacity) << endl;
}

void input(vector<int>& arr, int number)
{
  int temp;
  for(int i = 0; i < number; i++)
  {
    cin >> temp;
    arr.push_back(temp);
  }
}

void MultiBackPack(vector<int>& dp, int capacity, int value, int cap, int w)
{
  int bia = 0, sec, n_cap, n_value;
  while(w>0)
  {
    sec = pow(2,bia++);
    if(w > sec)
    {
      n_cap = sec * cap;
      n_value = sec * value;
      w -= sec;
    }
    else
    {
      n_cap = w * cap;
      n_value = w * value;
      w = 0;
    }
    for(int v = capacity; v >= n_cap; v--)
    {
      dp[v] = max(dp[v], dp[v - n_cap] + n_value);
    }
  }
}

void ComBackPack(vector<int>& dp, int capacity, int value, int cap)
{
  for(int v = cap; v <= capacity; v++)
  {
    dp[v] = max(dp[v], dp[v - cap] + value);
  }
}
