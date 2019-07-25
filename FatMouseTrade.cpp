#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 1000

typedef struct
{
  double b;
  double j;
  double m;
} stor;
stor house[N];

bool cmpx(stor m, stor n)
{
  return m.m > n.m;
}

int main()
{
  int fat, houseN, i;
  while(cin >> fat >> houseN && fat != -1 && houseN != -1)
  {
    for(i = 0; i < houseN; i++)
    {
      cin >> house[i].b >> house[i].j;
      house[i].m = house[i].b / house[i].j;
    }
    sort(house, house + houseN, cmpx);
    int i = 0;
    double sum = 0.0;
    while(fat > 0 && i < houseN)
    {
      if(house[i].j <= fat)
      {
        sum += house[i].b;
        fat -= house[i].j;
      }
      else
      {
        sum += house[i].m * fat;
        fat = 0;
      }
      i++;
    }
      cout << fixed << setprecision(3) << sum << endl;
  }
  return 0;
}
