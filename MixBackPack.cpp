#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void input(vector<int>&, int); // ��������
void MultiBackPack(vector<int>& dp, int capacity, int value, int cap, int w); // 0-1�����ر����������
void ComBackPack(vector<int>& dp, int capacity, int value, int cap); // ��ȫ�����������

int main()
{
  int item_number; // ��Ʒ����
  cout << "��������Ʒ����:" << endl;;
  cin >> item_number;
  vector<int> cap; //��������
  vector<int> value; //��ֵ����
  vector<int> section; // ѡ������
  cout << "��������Ʒ����:" << endl;;
  input(cap, item_number);
  cout << "��������Ʒ��ֵ:" << endl;
  input(value, item_number);
  cout << "������ÿ����Ʒ��ѡ�������:" << endl;
  input(section, item_number);
  int capacity; // ��������
  cout << "�����뱳������:" << endl;
  cin >> capacity;
  vector<int> dp(capacity+1, 0); //����״̬
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
