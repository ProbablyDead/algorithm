#include "ladder.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "../../array/arrOpt.hpp"

bool ladSearch (std::vector<std::vector<long long int> >& arr, int target) {
  for (int i = 0, j = 8191; i < arr.size(); ++i){
    if (arr[i][j] == target) {return true;}
    if (arr[i][j] < target) {continue;}
    for (; j > -1; --j){
      if (arr[i][j] == target) {return true;}
      if (arr[i][j] < target) {break;}
    }
  }
  return false;
}

void ladderSearch (int m, int n){
  vector<vector<long long int> > arr(m, vector<long long int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  ladSearch(arr, target);
  auto end1 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << "\t\t";

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  ladSearch(arr, target);
  auto end2 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void ladderSearchResult () {
  int n = 8192, m = 2;
  cout << "\n\tLadder Search:" << endl << "M\t\tFirst\tSecond\n";
  for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
    cout << "2**" << i << '\t';
    ladderSearch(m, n);
  }
}