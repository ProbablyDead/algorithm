#include "exp.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "../../array/arrOpt.hpp"

int binaryRow (vector<long long int>& arr, int target, int leftPoz, int rightPoz) {
  int center = (leftPoz + rightPoz)/2;

  if (arr[center] == target) { return center; }
  if (rightPoz == leftPoz) { return center; }
  if (leftPoz - rightPoz < 0) { return center; }
  if (arr[center] < target) { return binaryRow(arr, target, center, rightPoz); }
  if (arr[center] > target) { return binaryRow(arr, target, leftPoz, center); }

  return -1;
}

int binaryColumn (vector<vector<long long int> >& arr, int j, int target, int upperPoz, int bottomPoz) {
  int center = (upperPoz + bottomPoz)/2;

  if (arr[center][j] == target) { return center; }
  if (center == bottomPoz || center == upperPoz) { return bottomPoz;}
  if (upperPoz == bottomPoz) { return center; }
  if (upperPoz > bottomPoz) { return center; }
  if (arr[center][j] < target) { return binaryColumn(arr, j, target, center, bottomPoz); }
  if (arr[center][j] > target) { return binaryColumn(arr, j, target, upperPoz, center); }

  return -1;
}

bool expSearch (vector<vector<long long int> >& arr, int target, int m) {
  int i = 0, j = 8191;
  while (true) {
    int stepI = 1, stepJ = 1;

    for (; i + stepI < m; stepI <<= 1) {
      if (arr[i][j] > target) { break; }
      i += stepI;
    }

    i = binaryColumn(arr, j, target, i - (stepI >> 1), i);

    for (; j > -1; stepJ <<= 1) {
      if (arr[i][j] < target) { break; }
      j -= stepJ;
    }
    j = binaryRow(arr[i], target, j, j + (stepJ >> 1));

    if (i >= m - 1  || j <= 0) { return false; }
    if (arr[i][j] == target) { return true; }
  }
}

void exponentialSearch (int m, int n) {
  vector<vector<long long int> > arr(m, vector<long long int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  expSearch(arr, target, m);
  auto end1 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << "\t\t";

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  expSearch(arr, target, m);
  auto end2 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void exponentialSearchResult () {
  int n = 8192, m = 2;
  cout << "\n\tExponential Search:" << endl << "M\t\tFirst\tSecond\n";
  for (int i = 1; i < 14; ++i, m<<=1) {
    cout << "2**" << i << '\t';
    exponentialSearch(m, n);
  }
}