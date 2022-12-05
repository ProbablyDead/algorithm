#include "binary.hpp"
#include <vector>
#include <iostream>
#include "../../array/arrOpt.hpp"

bool binSearch(vector<vector<long long int> >& arr, int target) {
  for (auto& i : arr) {
    int left = 0, right = 8191;
    while (true) {
      int center = (left + right) / 2;
      if (i[center] == target) { return true; }
      if (center == left || center == right) { break; }
      if (left >= right) { break; }
      if (i[center] < target) {
        left = center;
        continue;
      }
      if (i[center] > target) {
        right = center;
        continue;
      }
    }
  }
  return false;
}

void binarySearch (int m, int n) {
  vector<vector<long long int> > arr(m, vector<long long int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  binSearch(arr, target);
  auto end1 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << "\t\t";

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  binSearch(arr, target);
  auto end2 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void binarySearchResult () {
  int n = 8192, m = 2;
  cout << "\tBinary Search:" <<  endl << "M\t\tFirst\tSecond\n";
	for (int i = 1; i < 14; ++i, m <<= 1) {
		  cout << "2**" << i << '\t';
    binarySearch(m, n);
	}
}
