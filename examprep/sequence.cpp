#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double el(int i) {
  double div = 0.0;
  for (int k = 1; k <= i; k++) {
    div += sin(k);
  }
  double res = (double)i / div;
  return res;
}

int main() {
  int n =1;
  // cin>>n;
  for (; n <= 100; n++) {
  double res = 0.0;
    for (int i = 1; i <= n; i++) {
      res += el(i);
    }
    cout.width(25);
    cout << setprecision(20) << res << endl;
  }
  return 0;
}
