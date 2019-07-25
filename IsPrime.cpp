#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;

bool prime(int k)
{
  for(int i = 2; i < sqrt(k); i++)
  {
    if(k % i == 0)
    {
      return false;
    }
  }
  return true;
}

bool isprime(int x, int y)
{
  for(int i = x; i <= y; i++)
  {
    if(!prime(i*i + i + 41))
    {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<int> x(2);
  vector<int>::iterator a;
  a = x.begin();
  while(cin >> *a >> *(a+1) && (*a != 0 || *(a+1) != 0))
  {
    if(isprime(*a, *(a+1)))
    {
      cout << "OK";
    }
    else
    {
      cout << "Sorry";
    }
    cout << endl;
  }
  return 0;
}
