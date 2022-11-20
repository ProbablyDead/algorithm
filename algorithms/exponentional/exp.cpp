#include "exp.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "../../array/arrOpt.hpp"

pair<int, bool> binary2 (vector<long long int>& arr, int target, int leftPoz, int rightPoz) {
  int center = (leftPoz + rightPoz)/2;

  if (arr[center] == target) {return make_pair(center,true);}
  if (rightPoz == leftPoz) {return make_pair(center, false);}
  if (leftPoz - rightPoz < 0) {return make_pair(center, false);}
  if (arr[center] < target) {binary2(arr, target, center, rightPoz);}
  if (arr[center] > target) {binary2(arr, target, leftPoz, center);}


  return make_pair(-1, false);
}

bool expSearch (std::vector<std::vector<long long int> >& arr, int target) {
  int n = 8191;
  for (auto & i : arr){
     for (int j = n, step = 2; j > -1; j-= step, step *=2){
       if (i[j] < target){
         pair rez = binary2(i, target, j, j + step);
         if (rez.second) {return true;}
         n = j;
         break;
       }
       if (i[j] == target) {return true;}
     }
  }
  return false;
}

void exponentialSearch (int m, int n){
  vector<vector<long long int> > arr(m, vector<long long int>(n));

  int target;

  target = firstFillArray(arr);
  auto start1 = chrono::system_clock::now();
  expSearch(arr, target);
  auto end1 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << "\t\t";

  target = secondFillArray(arr);
  auto start2 = chrono::system_clock::now();
  expSearch(arr, target);
  auto end2 = chrono::system_clock::now();

  cout << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << endl;
}

void exponentialSearchResult () {
  int n = 8192, m = 2;
  cout << "\n\tExponential Search:" << endl << "M\t\tFirst\tSecond\n";
  for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
    cout << "2**" << i << '\t';
    exponentialSearch(m, n);
  }
}