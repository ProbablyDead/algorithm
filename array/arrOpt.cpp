#include "arrOpt.hpp"
#include <vector>

int firstFillArray (vector<vector<long long int> >& arr) {
  int a = 0, b = 0, n = static_cast<int>(arr[0].size()), m = static_cast<int>(arr.size());
	for (auto & i : arr) {
		for (auto & j : i) {
			j = (n/m*(a++) + (b++))*2;
		}
	}
  return 2*n + 1;
}

int secondFillArray (vector<vector<long long int> >& arr) {
  int a = 0, b = 0, n = static_cast<int>(arr[0].size()), m = static_cast<int>(arr.size());
  for (auto & i : arr) {
    for (auto & j : i) {
      j = (n/m*(a++) * (b++))*2;
    }
  }
	return 16*n + 1;
}

