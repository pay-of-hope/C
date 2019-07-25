#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
  vector<char> ascii(3);
  vector<char>::iterator a;
  a = ascii.begin();
  while(cin >> *a >> *(a + 1) >> *(a + 2))
  {
    sort(ascii.begin(), ascii.end());
    cout << *a << ' ' << *(a+1) << ' ' << *(a+2) << endl;
    }
  return 0;
}
