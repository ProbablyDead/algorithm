#include "exp.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "../../array/arrOpt.hpp"

bool expSearch (std::vector<std::vector<int> >& arr, int target) {
  int n = static_cast<int>(arr[0].size()) - 1, m = static_cast<int>(arr.size());
  for (auto i : arr){
    int ex = 2;
    while (n - ex < m && i[n - ex] > target){
      ex*=2;
    }
    if (binary_search(i.end() - ex, i.end() - ex/2, target))
      return true;
  }
  return false;
}

void exponentialSearch (int m, int n){
  vector<vector<int> > arr(m, vector<int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  expSearch(arr, target);
  auto end1 = chrono::system_clock::now();

  cout << "\t\tFirst fill: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << endl;

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  expSearch(arr, target);
  auto end2 = chrono::system_clock::now();

  cout << "\t\tSecond fill " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void exponentialSearchResult () {
  int n = 8192, m = 2;
  cout << "Exponential Search:" << endl;
  for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
      cout << "\tm = 2**" << i << endl;
    exponentialSearch(m, n);
  }
}