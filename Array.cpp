#include <iostream>
using namespace std;
int main()
{
  int arr[] = {13, 25, 39, 49, 52, 67, 88, 89, 81, 72, 84, 92};
  int si = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < si; i++)
  {
    int smi = i;
    for (int j = i + 1; j < si; j++)
    {
      if (arr[j] < arr[smi])
        smi = j;
    }
    int temp = arr[i];
    arr[i] = arr[smi];
    arr[smi] = temp;
  }
  for (int i = 0; i < si; i++)
  {
    cout << arr[i] << ",";
  }
  return 0;
}