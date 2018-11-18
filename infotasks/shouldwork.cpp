#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#define _USE_MATH_DEFINES

using namespace std;

void sorting(int a[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int base = a[(left + right) / 2];
  while (i <= j) {
    while (a[i] < base)
    i++;
    while (a[j] > base)
    j--;
    if (i <= j) {
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }
  }
  if (left < j)
    sorting(a, left, j);
  if (right > i)
    sorting(a, i, right);
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
  sorting(a, 0, m - 1);
  cout<< endl;
  for (int i = 0; i < m; i++) {
    cout << a[i] << ' ';
  }
}
