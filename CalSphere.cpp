#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
  double pho;
  const double PI = 3.1415927;
  while(cin >> pho)
  {
  cout << fixed << setprecision(3) << 4 * PI / 3 * pho * pho * pho << endl;
}
}
