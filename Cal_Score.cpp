/**
 * 问题描述：
 * 青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
 *
 * 输入：
 * 输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
 *
 * 输出：
 * 对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
 * @return [description]
 */




#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int score_num ;
  double sum, low, high, temp;
  while(cin >> score_num)
  {
    sum = 0.0;
    cin >> high >> low;
    if(high < low)
    {
      temp = high;
      high = low;
      low = temp;
    }
    for(int i = 2; i < score_num; i++)
    {
      cin >> temp;
      if(temp > high)
      {
        sum += high;
        high = temp;
      }
      else if(temp < low)
      {
        sum += low;
        low = temp;
      }
      else
      {
        sum += temp;
      }
    }
    cout << fixed << setprecision(2) << sum / (score_num-2) << endl;
  }
  return 0;
}
