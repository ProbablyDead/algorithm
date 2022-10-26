#include "ladder.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "../../array/arrOpt.hpp"

bool ladSearch (std::vector<std::vector<int> >& arr, int target) {
  for (int i = 0, j = static_cast<int>(arr[0].size()) - 1; i < static_cast<int>(arr.size()); ++i){
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
  vector<vector<int> > arr(m, vector<int>(n));

  int target = firstFillArray(arr);
  clock_t startTime =  clock();
  ladSearch(arr, target);
  clock_t endTime =  clock();

  cout << "\t\tFirst filling " << (double)(endTime - startTime)/CLOCKS_PER_SEC << endl;

  target = secondFillArray(arr);
  startTime =  clock();
  ladSearch(arr, target);
  endTime =  clock();

  cout << "\t\tSecond filling " << (double)(endTime - startTime)/CLOCKS_PER_SEC << endl;
}

void ladderSearchResult () {
  int n = 8192, m = 2;
  cout << "Ladder Search:" << endl;
  for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
    cout << "\tm = 2**" << i << endl;
    ladderSearch(m, n);
  }
}