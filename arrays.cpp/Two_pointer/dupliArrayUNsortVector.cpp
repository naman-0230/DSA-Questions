#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n, k, i, j;
  cout << "enter no. of elements" << endl;
  cin >> n;

  int arr[n];
  cout << "enter array numbers";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> v;
  v.push_back(arr[0]);
  for (int i = 1; i < n; ++i)
  {
    bool x = false;
    for (int j = 0; j < v.size(); ++j)
    {
      if (arr[i] == v[j]){
        x = true;
      break;}
    }

    if (!x)
      v.push_back(arr[i]);
  }
for (int i = 0; i < v.size(); i++)
  cout << v[i] << " ";
  return 0;
}