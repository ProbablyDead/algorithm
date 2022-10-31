#include "binary.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "../../array/arrOpt.hpp"

pair<int, bool> binary (vector<int>& arr, int target, int leftPoz, int rightPoz) {
  int center = (leftPoz + rightPoz)/2;

  if (arr[center] == target) {return make_pair(center,true);}
  if (rightPoz == leftPoz) {return make_pair(center, false);}
  if (leftPoz - rightPoz < 0) {return make_pair(center, false);}
  if (arr[center] < target) {binary(arr, target, center, rightPoz);}
  if (arr[center] > target) {binary(arr, target, leftPoz, center);}


  return make_pair(-1, false);
}

bool binSearch (vector<vector<int> >& arr, int target) {
	for (auto & i : arr){
    pair rez = binary(i, target, 0, (int)pow(2, 13));
    if (rez.second) {return true;}
		}
  return (false);
}

void binarySearch (int m, int n) {
	vector<vector<int> > arr(m, vector<int>(n));

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
  cout << "\tBinary Search:" << endl << "M\t\tFirst\tSecond\n";
	for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
		  cout << "2**" << i << '\t';
    binarySearch(m, n);
	}
}