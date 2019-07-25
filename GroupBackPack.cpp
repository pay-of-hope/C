#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void input(vector<vector<int>>&, int, int); //����
int main()
{
  int K; // ��Ʒ����
  cout << "��������Ʒ����:" << endl;
  cin >> K;
  vector<vector<int>> cap(K);
  vector<vector<int>> value(K);
  for(int i = 0; i < K; i++)
  {
    int k;
    cout << "�������" << i+1 << "����Ʒ����:" << endl;
    cin >> k;
    cout << "�������" << i+1 << "����Ʒ��������:" << endl;
    input(cap, i, k);
    cout << "�������" << i+1 << "����Ʒ��ֵ����:" << endl;
    input(value, i, k);
  }
  int capacity;
  cout << "�����뱳������:" << endl;
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
