/**
 * ���ر�������
 */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//**������Ʒ��������ֵ��ÿ����Ʒ���ɷŵ�����
void get_data(vector<int> &, int);
void con(vector<int> &, vector<int> &, int, int, int);

int main()
{
  vector<int> cap;
  vector<int> value;
  vector<int> w;
  int n, i = 0;
  cout << "����һ���м�����ͬ����Ʒ��" << endl;
  cin >> n;
  cout << "�����������飺" << endl;
  get_data(cap, n);
  cout << "�����ֵ���飺" << endl;
  get_data(value, n);
  cout << "�����ѡ�������飺" << endl;
  get_data(w, n);
  //**ת��Ϊ0-1��������
  vector<int> new_cap;
  vector<int> new_value;
  vector<int>::iterator cap_;
  vector<int>::iterator value_;
  vector<int>::iterator w_;
  w_ = w.begin();
  cap_ = cap.begin();
  value_ = value.begin();
  while(i < n)
  {
    con(new_cap, new_value, *(w_+i), *(value_+i), *(cap_+i));
    i++;
  }
  //**0-1��������
  int capacity;
  cout << "�����뱳����С��" << endl;
  cin >> capacity;
  vector<int> dp(capacity+1, 0);
  w_ = dp.begin();
  cap_ = new_cap.begin();
  value_ = new_value.begin();
  for(int i = 0; i < new_cap.size(); i++)
  {
    for(int v = capacity; v >= *(cap_+i); v--)
    {
      *(w_+v) = max(*(w_+v), *(w_+v-*(cap_+i))+*(value_+i));
    }
  }
  cout << *(w_+capacity) << endl;
  return 0;
}

void get_data(vector<int> &arr, int n)
{
  int i = 0, num;
  while(i++ < n)
  {
    cin >> num;
    arr.push_back(num);
  }
}

void con(vector<int> &cap, vector<int> &value, int w, int v, int c)
{
  int bia = 0;
  while(true)
  {
    int cc = pow(2,bia++);
    if(w > cc)
    {
      cap.push_back(c*cc);
      value.push_back(v*cc);
      w -= cc;
    }
    else
    {
      cap.push_back(c*w);
      value.push_back(v*w);
      return;
    }
  }
}
