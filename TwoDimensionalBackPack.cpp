/**
 * ��ά���ѵı�������
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T1, typename T2> void input(T1&, T2); // ¼������
void ComBackPack(vector<vector<int>>&, int, int, int, int, int); // ��ȫ�����������
void MultiBackPack(vector<vector<int>>&, int, int, int, int, int, int); // 0-1�����ر����������

int main()
{
  int item_number; // ��Ʒ����
  cout << "��������Ʒ����:" << endl;
  cin >> item_number;
  vector<int> cap; //��Ʒ��������
  vector<int> vol;
  vector<int> value; //��Ʒ��ֵ����
  vector<int> section; //��Ʒ��ѡ����
  cout << "��������Ʒ��������c:" << endl;
  input(cap, item_number);
  cout << "��������Ʒ��������v:" << endl;
  input(vol, item_number);
  cout << "��������Ʒ��ֵ����:" << endl;
  input(value, item_number);
  cout << "��������Ʒ��ѡ��������:" << endl;
  input(section, item_number);
  int capacity, volume;
  cout << "�����뱳������c:" << endl;
  cin >> capacity;
  cout << "�����뱳������v:" << endl;
  cin >> volume;
  vector<vector<int>> dp(capacity+1); //����״̬
  for(int i = 0; i <= capacity; i++)
  {
    dp[i].resize(volume);
  }
  vector<int>::iterator cap_iter, vol_iter, value_iter, section_iter;
  vector<vector<int>> dp_iter;
  cap_iter = cap.begin();
  vol_iter = vol.begin();
  value_iter = value.begin();
  section_iter = section.begin();
  for(int i = 0; i < item_number; i++)
  {
    if(*(section_iter+i) != -1)
    {
      MultiBackPack(dp, *(cap_iter+i), *(vol_iter+i), *(value_iter+i), *(section_iter+i), capacity, volume);
    }
    else
    {
      ComBackPack(dp, *(cap_iter+i), *(vol_iter+i), *(value_iter+i), capacity, volume);
    }
  }
  cout << dp[capacity][volume] << endl;
  return 0;
}

template<typename T1, typename T2>
void input(T1& arr, T2 n)
{
  T2 num;
  for(T2 i = 0; i < n; i++)
  {
    cin >> num;
    arr.push_back(num);
  }
}

void ComBackPack(vector<vector<int>>& dp, int cap, int vol, int value, int capacity, int volume)
{
  for(int c = cap; c <= capacity; c++)
  {
    for(int v = vol; v <= volume; v++)
    {
      dp[c][v] = max(dp[c][v], dp[c-cap][v-vol]+value);
    }
  }
}

void MultiBackPack(vector<vector<int>>& dp, int cap, int vol, int value, int w, int capacity, int volume)
{
  int bia = 0, sec, n_cap, n_vol, n_value;
  while(w > 0)
  {
    sec = pow(2, bia++);
    if(w > sec)
    {
      n_cap = sec * cap;
      n_vol = sec * vol;
      n_value = sec * value;
      w -= sec;
    }
    else
    {
      n_cap = cap * w;
      n_value = value * w;
      n_vol = vol * w;
      w = 0;
    }
    for(int c = capacity; c >= n_cap; c--)
    {
      for(int v = volume; v >= n_vol; v--)
      {
        dp[c][v] = max(dp[c][v], dp[c-n_cap][v-n_vol]+n_value);
      }
    }
  }
}
