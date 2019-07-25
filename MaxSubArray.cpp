#include<iostream>
#include<ctime>
using namespace std;

int subarray(int arr[16], int low, int high)
{
  if(low == high)
  {
    return arr[low];
  }
  else
  {
    int mid = (low + high) >> 1;
    int left_max = subarray(arr, low, mid);
    int right_max = subarray(arr, mid+1, high);
    int i, sum, left_mid = INT_MIN, mid_right = INT_MIN;
    for(i = mid, sum = 0; i >= low; i--)
  {
    sum += arr[i];
    if(sum > left_mid)
    {
      left_mid = sum;
    }
  }
    for(i = mid+1, sum = 0; i <= high; i++)
  {
    sum += arr[i];
    if(sum > mid_right)
    {
      mid_right = sum;
    }
  }
    int left_mid_right = left_mid + mid_right;
    int max = left_max > right_max?left_max:right_max;
    max = max > left_mid_right?max:left_mid_right;
    return max;
  }
}

int main()
{
  long long t_1 = clock();
  int arr[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,13,-5,-22,15,-4,7};
  int low = 0, high = 15;
  cout << subarray(arr, low, high) << endl;
  long long t_2 = clock();
  cout << t_2 - t_1 << endl;
  return 0;
}
