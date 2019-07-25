/**
 * 问题描述：
 * 你曾经在操场上玩quoit吗?Quoit是一种游戏，在游戏中，扁环被扔向一些玩具，所有的玩具都被奖励。
 * 在Cyberground领域中，每个玩具的位置都是固定的，并且环是经过精心设计的，每次只能环绕一个玩具。
 * 另一方面，为了使游戏看起来更有吸引力，环的设计有最大的半径。给定一个场的构型，你应该求出这样一个环的半径。
 * 假设所有的玩具都是平面上的点。如果点到环中心的距离严格小于环的半径，则点被环包围。如果两个玩具放置在同一点，则圆环半径为0。
 *
 * 输入：
 * 输入由几个测试用例组成。对于每种情况，第一行包含一个整数N (2 <= N <= 100,000)，即字段中玩具的总数。
 * 然后是N行，每一行包含一对(x, y)这是一个玩具的坐标。输入被N = 0终止。
 *
 * 输出：
 * 对于每个测试用例，在一行中打印Cyberground manager要求的圆环半径，精确到小数点后两位。
 */


#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>

#define numMax 100005

using namespace std;

typedef struct
{
  double x;
  double y;
} Axis;

Axis axis[numMax], coord[numMax];

bool cmpx(Axis temp_1, Axis temp_2)
{
  return temp_1.x < temp_2.x;
}

bool cmpy(Axis temp_1, Axis temp_2)
{
  return temp_1.y < temp_2.y;
}

double min(double i, double j)
{
  if(i > j)
  {
    return j;
  }
  else{
    return i;
  }
}
double cal_dis(Axis i, Axis j)
{
  return sqrt((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y));
}

double quoit(int lt, int rt)
{
  if(lt == rt)
  {
    return 1000000.0;
  }
  else if(lt + 1 == rt)
  {
    return cal_dis(axis[lt], axis[rt]);
  }
  else
  {
    int mid =(lt + rt) >> 1;
    double d1 = quoit(lt, mid);
    double d2 = quoit(mid + 1, rt);
    double d = min(d1, d2);
    int i, k;
    int j = 0;
    for(i = lt; i <= rt; i++)
    {
      if(axis[i].x < axis[mid].x + d && axis[i].x > axis[mid].x - d)
      {
        coord[j].x = axis[i].x;
        coord[j++].y = axis[i].y;
      }
    }
    sort(coord, coord + j, cmpy);
    for(i = 0; i < j; i++){
      for(k = i + 1; k < j; k++)
      {
        if( axis[k].y - axis[i].y >= d)
        {
          break;
        }
        double t = cal_dis(coord[i], coord[k]);
        d = min(d, t);
      }
    }
    return d;
    }
  }
int main()
{
  int point_n, i;
  while( cin >> point_n && point_n != 0)
  {
    for(i = 0; i < point_n; i++ )
  {
      cin >> axis[i].x >> axis[i].y;
  }
    sort(axis, axis + point_n - 1, cmpx);
    cout <<fixed << setprecision(2) << quoit(0, point_n - 1) / 2 << endl;
}
  return 0;
}
