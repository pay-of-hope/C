#include<iostream>
using namespace std;

int main()
{
  int floorNum, floor;
  while(cin >> floorNum && floorNum != 0)
  {
    int floor, curFloor = 0, time = 0;
    for(int i = 0; i < floorNum; i++)
    {
      cin >> floor;
      int dif = floor - curFloor;
      if(dif > 0)
      {
        time = time + dif * 6 + 5;
      }
      else if(dif < 0)
      {
        time = time - dif * 4 + 5;
      }
      else
      {
        time += 5;
      }
      curFloor = floor;
    }
    cout << time << endl;
  }
  return 0;
}
