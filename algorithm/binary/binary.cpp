#include "binary.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "../../array/arrOpt.hpp"

void binSearch (vector<vector<int> >& arr, int target) {
	for (auto i : arr){
			binary_search (i.begin(), i.end(), target);
		}
}

void binarySearch (int m, int n){
	vector<vector<int> > arr(m, vector<int>(n));

  int target;

	target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  binSearch(arr, target);
  auto end1 = chrono::system_clock::now();

  cout << "\t\tFirst fill: " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << endl;

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  binSearch(arr, target);
  auto end2 = chrono::system_clock::now();

  cout << "\t\tSecond fill " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void binarySearchResult () {
  int n = 8192, m = 2;
  cout << "Binary Search:" << endl;
	for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
		  cout << "\tm = 2**" << i << endl;
    binarySearch(m, n);
	}
}
