#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#define _USE_MATH_DEFINES

using namespace std;

void quickSorti(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };
  for (int i = 0; i < 12; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
  /* recursion */
  if (left < j)
    quickSorti(arr, left, j);
  if (i < right)
    quickSorti(arr, i, right);
}

int main() {

  int n = 0;
  cin >> n;
  int a[n];
  srand(time(NULL));
  int m = sizeof(a) / sizeof(*a);
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    a[i] = rand() % n;
  }
  for (int i = 0; i < m; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
  quickSorti(a, 0, m - 1);
  cout<< endl;
  for (int i = 0; i < m; i++) {
    cout << a[i] << ' ';
  }
}
