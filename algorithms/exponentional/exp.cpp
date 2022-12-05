#include "exp.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "../../array/arrOpt.hpp"

int binSearchColumn(vector<long long int>& arr, int target, int rightPoz, int leftPoz) {
  int center = (leftPoz + rightPoz) / 2;
  while (true) {
    center = (leftPoz + rightPoz) / 2;
    if (arr[center] == target) { break; }
    if (center == leftPoz || center == rightPoz) { break; }
    if (leftPoz >= rightPoz) { break; }
    if (arr[center] < target) {
      leftPoz = center;
      continue;
    }
    if (arr[center] > target) {
      rightPoz = center;
      continue;
    }
  }
  return center;
}

int binSearchRow(vector<vector<long long int> >& arr, int target, int upperPoz, int bottomPoz, int column) {
  int center = (upperPoz + bottomPoz) / 2;
  while (true) {
    center = (upperPoz + bottomPoz) / 2;
    if (arr[center][column] == target) { break; }
    if (center == upperPoz || center == bottomPoz) { return bottomPoz; }
    if (upperPoz >= bottomPoz) { break; }
    if (arr[center][column] < target) {
      upperPoz = center;
      continue;
    }
    if (arr[center][column] > target) {
      bottomPoz = center;
      continue;
    }
  }
  return center;
}

bool expSearch (vector<vector<long long int> >& arr, int target, int m) {
  int i = 0, j = 8191;
  while (true) {
    int stepI = 1, stepJ = 1;

    for (; i + stepI < m; stepI <<= 1) {
      if (arr[i][j] > target) { break; }
      i += stepI;
    }

    i = binSearchRow(arr, target, i - (stepI >> 1), i, j);

    for (; j > -1; stepJ <<= 1) {
      if (arr[i][j] < target) { break; }
      j -= stepJ;
    }
    j = binSearchColumn(arr[i], target, j + (stepJ >> 1), j);

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