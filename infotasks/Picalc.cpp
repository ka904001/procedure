#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
uint64_t circle = 0;
double x = 0, y = 0;
int main() {
  int times;
  times = 1000000000;
  srand(time(NULL));
  for (int i = 0; i < times; i++) {
    ::x = (double)(rand() % 10000) / 10000.0;
    //cout << x << ' ';
    ::y = (double)(rand() % 10000) / 10000.0;
    //cout << y << endl;
      if((x*x + y*y)<=1){
      ::circle++;
      }
  }
  // cout<<circle<<"  "<<all<<endl;
  double pim = 4 * ((double)circle / (double)times);
  cout << pim;
  return 0;
}
