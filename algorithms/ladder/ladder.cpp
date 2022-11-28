#include "ladder.hpp"
#include <vector>
#include <iostream>
#include "../../array/arrOpt.hpp"

bool ladSearch (vector<vector<long long int> >& arr, int target, int m) {
  int i = 8191, j = 0;
  while (i >= 0 && j < m) {
      if (arr[j][i] == target) { return true; }
      else {
          if (arr[j][i] > target) { --i; }
          else { ++j; }
      }
  }
  return false;
}

void ladderSearch (int m, int n) {
  vector<vector<long long int> > arr(m, vector<long long int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  ladSearch(arr, target, m);
  auto end1 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << "\t\t";

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  ladSearch(arr, target, m);
  auto end2 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void ladderSearchResult () {
  int n = 8192, m = 2;
  cout << "\n\tLadder Search:" << endl << "M\t\tFirst\tSecond\n";
  for (int i = 1; i < 14; ++i, m <<= 1) {
    cout << "2**" << i << '\t';
    ladderSearch(m, n);
  }
}
