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

	int target = firstFillArray(arr);
	clock_t startTime =  clock();
  binSearch(arr, target);
	clock_t endTime =  clock();

	cout << "\t\tFirst filling " << (double)(endTime - startTime)/CLOCKS_PER_SEC << endl;

	target = secondFillArray(arr);
	startTime =  clock();
  binSearch(arr, target);
	endTime =  clock();

	cout << "\t\tSecond filling " << (double)(endTime - startTime)/CLOCKS_PER_SEC << endl;
}

void binarySearchResult () {
  int n = 8192, m = 2;
  cout << "Binary Search:" << endl;
	for (int i = 1; i < 14; ++i, m = (int)pow(2,i)) {
		cout << "\tm = 2**" << i << endl;
    binarySearch(m, n);
	}
}
