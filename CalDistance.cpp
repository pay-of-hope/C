#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
  vector<double> axis(4);
  vector<double>::iterator a;
  a = axis.begin();
  while(cin >> *a >> *(a+1) >> *(a+2) >> *(a+3))
  {
    double dis = sqrt(pow(*a - *(a+2), 2) + pow(*(a+1) - *(a+3),2));
    cout << fixed << setprecision(2) << dis << endl;
  }
  return 0;
}
