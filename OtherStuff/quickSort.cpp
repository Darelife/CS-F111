#include <bits/stdc++.h>
using namespace std;

#define la(i, a, b) for (int i = a; i < b; i++)

vector<int> qSort(vector<int> v) {
  // int pivot = v.size() / 2;
  // la(i, 0, v.size()) {
  //   if (i == pivot)
  //     continue;
  //   if (v[i] < v[pivot]) {
  //     // swap
  //     int temp = v[i];
  //     v[i] = v[pivot];
  //     v[pivot] = temp;
  //   }
  // }
  // vector<int> left, right;
  // la(i, 0, v.size()) {
  //   if (i == pivot)
  //     continue;
  //   if (v[i] < v[pivot])
  //     left.push_back(v[i]);
  //   else
  //     right.push_back(v[i]);
  // }
  // if (left.size() > 1)
  //   qSort(left);
  // if (right.size() > 1)
  //   qSort(right);
  // vector<int> sorted;
  // la(i, 0, left.size()) sorted.push_back(left[i]);
  // sorted.push_back(v[pivot]);
  // la(i, 0, right.size()) sorted.push_back(right[i]);
  // return sorted;

  if (v.size() <= 1)
    return v;
  vector<int> left, right;
  int pivot = v.size() / 2;
  la(i, 0, v.size()) {
    if (i == pivot)
      continue;
    if (v[i] < v[pivot])
      left.push_back(v[i]);
    else
      right.push_back(v[i]);
  }
  left = qSort(left);
  right = qSort(right);
  vector<int> sorted;
  la(i, 0, left.size()) sorted.push_back(left[i]);
  sorted.push_back(v[pivot]);
  la(i, 0, right.size()) sorted.push_back(right[i]);
  return sorted;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vector<int> sorted = qSort(v);
  la(i, 0, sorted.size()) cout << sorted[i] << " ";
  cout << "\n";
  return 0;
}